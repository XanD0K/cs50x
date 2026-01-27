import os
import re
import sqlite3

from cs50 import SQL
from datetime import datetime
from flask import Flask, flash, redirect, render_template, request, session, g
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Setting up a key for 'flash'
app.secret_key = os.urandom(24)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


# Using flask 'g' object to store user's username and cash. Will avoid redundancy queries
@app.before_request
def before_request():
    if "user_id" in session:
        user = db.execute("SELECT username, cash FROM users WHERE id = ?", session["user_id"])
        g.user = {
            "username": user[0]["username"],
            "cash": user[0]["cash"]
        }
    else:
        g.user = None


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    holdings = db.execute(
        "SELECT symbol, shares, avg_price FROM portfolio WHERE user_id = ? ORDER BY symbol", session["user_id"])
    stocks_value_total = 0
    portfolio_total = g.user["cash"]

    # Assigning names to holdings' columns
    for holding in holdings:
        holding_info = lookup(holding["symbol"])
        holding["name"] = holding_info["name"]
        holding["current_price"] = holding_info["price"]
        stock_total = holding["current_price"] * holding["shares"]
        stocks_value_total += stock_total
        portfolio_total += stock_total

    return render_template("index.html", username=g.user["username"], cash=g.user["cash"], holdings=holdings, portfolio_total=portfolio_total, stocks_value_total=stocks_value_total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # Accessing buy page
    if request.method == "GET":
        # Checking if user got redirected from 'quoted.html' or from 'index.html'
        symbol = request.args.get("symbol")
        if symbol:
            symbol = symbol.upper()
            stock_info = lookup(symbol)
            if stock_info is None:
                return render_template("buy.html", error="That's not a valid stock"), 400
            return render_template("buy.html", username=g.user["username"], cash=g.user["cash"], symbol=symbol, company_name=stock_info["name"], price=stock_info["price"])
        return render_template("buy.html")

    # Submitting buy form
    # It starst with a 'search' default form (just like 'quote.html')
    if request.method == "POST":
        form_type = request.form.get("form_type")
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        if not symbol:
            return render_template("buy.html", error="Enter a stock before search"), 400
        symbol = symbol.upper()

        # Buy form. It will only be displayed if user search for a valid stock
        stock_info = lookup(symbol)
        if stock_info is None:
            return render_template("buy.html", error="That's not a valid stock"), 400

        if form_type == "search":
            return redirect(f"/buy?symbol={symbol}")
        if form_type == "submit":
            if not shares:
                return render_template("buy.html", error="Enter a number of shares to buy", symbol=symbol, company_name=stock_info["name"], price=stock_info["price"], username=g.user["username"], cash=g.user["cash"]), 400

        if symbol and shares:
            stock_info = lookup(symbol)
            try:
                shares = int(shares)
                if shares < 1:
                    return render_template("buy.html", error="Enter a valid number of shares", symbol=symbol, company_name=stock_info["name"], price=stock_info["price"], username=g.user["username"], cash=g.user["cash"]), 400
            except ValueError:
                return render_template("buy.html", error="Enter a valid number of shares", symbol=symbol, company_name=stock_info["name"], price=stock_info["price"], username=g.user["username"], cash=g.user["cash"]), 400

            # Updating informations (specially price) before purchase
            stock_info = lookup(symbol)
            total_cost = shares * stock_info["price"]

            if total_cost > g.user["cash"]:
                return render_template("buy.html", error="You don't have enough money", symbol=symbol, company_name=stock_info["name"], price=stock_info["price"], username=g.user["username"], cash=g.user["cash"]), 400

            # Updating databases
            # Updating user's portfolio
            existed_row = db.execute(
                "SELECT shares, avg_price FROM portfolio WHERE user_id = ? AND symbol = ?", session["user_id"], symbol)
            now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

            if existed_row:
                # Calculating new average price
                current_shares = existed_row[0]["shares"]
                current_avg_price = existed_row[0]["avg_price"]
                new_shares = current_shares + shares
                new_avg_price = round(((current_shares * current_avg_price) +
                                      (stock_info["price"] * shares)) / new_shares, 2)
                db.execute("UPDATE portfolio SET shares = ?, avg_price = ? WHERE user_id = ? AND symbol = ?",
                           new_shares, new_avg_price, session["user_id"], symbol)
            else:
                db.execute("INSERT INTO portfolio (user_id, symbol, shares, avg_price) VALUES (?, ?, ?, ?)",
                           session["user_id"], symbol, shares, round(stock_info["price"], 2))

            # Updating user's cash
            db.execute("UPDATE users SET cash = cash - ? WHERE id = ?",
                       total_cost, session["user_id"])
            # Updating transactions history
            db.execute("INSERT INTO history (user_id, symbol, shares, price, type, date) VALUES (?, ?, ?, ?, 'BUY', ?)",
                       session["user_id"], symbol, shares, stock_info["price"], now)

            flash(
                f"Congratulations! You bought {shares} shares of {stock_info["name"]} for {usd(total_cost)}", "success")
            return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    history = db.execute(
        "SELECT symbol, shares, price, type, date FROM history WHERE user_id = ? ORDER BY date DESC", session["user_id"])

    for row in history:
        stock_info = lookup(row["symbol"])
        row["name"] = stock_info["name"]

    return render_template("history.html", history=history, username=g.user["username"], cash=g.user["cash"])


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE LOWER(username) = LOWER(?)", request.form.get("username")
        )
        # Added LOWER() in the login route to make it case insensitve, just like I did in the register route
        # 'rows' is a list of dictionaries, each of them representing a matching row from the database
        # It uses 'rows[0]' since there will be only one dictionary for that 'username'

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # Accessing the quote form
    if request.method == "GET":
        return render_template("quote.html")

    # Submitting the quote form
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        if not symbol:
            return render_template("quote.html", error="Missing Stock Symbol"), 400

        stock_info = lookup(symbol)
        if stock_info is None:
            return render_template("quote.html", error="Invalid Stock Symbol"), 400

        return render_template("quoted.html", symbol=symbol, company_name=stock_info["name"], price=stock_info["price"])


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # Accessing the registration form
    if request.method == "GET":
        return render_template("register.html")

    # Submitting the registration form
    if request.method == "POST":
        # Accessing and validating the form data
        username = request.form.get("username")
        if not username:
            return render_template("register.html", error="Missing username"), 400
        if re.match(r"^[a-zA-Z0-9'_-]+$", username) is None:
            return render_template("register.html", error="Don't use special characters for username", username=username), 400

        password = request.form.get("password")
        if not password:
            return render_template("register.html", error="Missing password", username=username), 400
        if len(password) < 8:
            return render_template("register.html", error="Password must be at least 8 digits", username=username), 400

        confirmation = request.form.get("confirmation")
        if not confirmation:
            return render_template("register.html", error="Missing confirmation password", username=username), 400

        if password != confirmation:
            return render_template("register.html", error="Passwords don't match", username=username), 400

        # Case sensitive check. Dismisses the necessity of the "try-except" block
        existed_user = db.execute(
            "SELECT username FROM users WHERE LOWER(username) = LOWER(?)", username)
        if len(existed_user) > 0:
            return render_template("register.html", error="Username not available. Choose another"), 400

        # Was getting error messages because I set it as a required feature. Changed it to optional
        security_answer = request.form.get("security_answer")
        if not security_answer:
            security_answer = "default"
        # Making it incase sensitive
        security_answer = security_answer.lower()

        if re.match(r"^[a-zA-Z0-9'-]+$", security_answer) is None:
            return render_template("register.html", error="Don't use special characters in your secret answer", username=username), 400

    # Inserting data in the database
    # The try-except is redundant since I'm already checking it with the case sensitive cases
    hash_password = generate_password_hash(password)
    try:
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash_password)
        # Get recen created user_id
        user_id = db.execute("SELECT id FROM users WHERE username = ?", username)[0]["id"]
        # Inserting into security database
        hash_answer = generate_password_hash(security_answer)
        db.execute("INSERT INTO security (user_id, answer_hash) VALUES (?, ?)", user_id, hash_answer)
    except sqlite3.IntegrityError:
        return render_template("register.html", error="Username not available. Choose another"), 400

    flash("Successfully registered!", "success")
    return redirect("/login")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "GET":
        # Checking if user got redirected from 'index.html'
        symbol = request.args.get("symbol")
        if symbol:
            symbol = symbol.upper()
            symbols = db.execute(
                "SELECT symbol FROM portfolio WHERE user_id = ?", session["user_id"])
            stock_info = lookup(symbol)
            # Safety check
            if stock_info is None:
                return render_template("sell.html", error="Couldn't retrieve stock's information. Try again later.", symbols=symbols), 400
            total_shares = db.execute(
                "SELECT shares FROM portfolio WHERE user_id = ? AND symbol = ?", session["user_id"], symbol)[0]["shares"]
            return render_template("sell.html", username=g.user["username"], cash=g.user["cash"], symbol=symbol, symbols=symbols, company_name=stock_info["name"], price=stock_info["price"], total_shares=total_shares)

        symbols = db.execute("SELECT symbol FROM portfolio WHERE user_id = ?", session["user_id"])
        return render_template("sell.html", symbols=symbols)

    if request.method == "POST":
        form_type = request.form.get("form_type")
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        symbols = db.execute("SELECT symbol FROM portfolio WHERE user_id = ?", session["user_id"])
        if not symbol:
            return render_template("sell.html", error="Select a stock to sell", symbols=symbols), 400
        symbol = symbol.upper()

        stock_info = lookup(symbol)
        if stock_info is None:
            return render_template("sell.html", error="Couldn't retrieve stock's information. Try again later.", symbols=symbols), 400

        symbols = db.execute("SELECT symbol FROM portfolio WHERE user_id = ?", session["user_id"])
        total_shares = db.execute(
            "SELECT shares FROM portfolio WHERE user_id = ? AND symbol = ?", session["user_id"], symbol)[0]["shares"]
        if form_type == "select":
            return redirect(f"/sell?symbol={symbol}")

        if form_type == "sell":
            if not shares:
                return render_template("sell.html", error="Enter a number of shares to sell", symbol=symbol, company_name=stock_info["name"], price=stock_info["price"], username=g.user["username"], cash=g.user["cash"], symbols=symbols, total_shares=total_shares), 400

        # Selling
        if symbol and shares:
            try:
                shares = int(shares)
                if shares < 1:
                    return render_template("sell.html", error="Enter a valid number of shares", symbol=symbol, company_name=stock_info["name"], price=stock_info["price"], username=g.user["username"], cash=g.user["cash"], symbols=symbols, total_shares=total_shares), 400

            except ValueError:
                return render_template("sell.html", error="Enter a valid number of shares", symbol=symbol, company_name=stock_info["name"], price=stock_info["price"], username=g.user["username"], cash=g.user["cash"], symbols=symbols, total_shares=total_shares), 400

            # Update informations (specially price) before selling
            stock_info = lookup(symbol)
            if stock_info is None:
                return render_template("sell.html", error="Couldn't retrieve stock's information. Try again later", symbols=symbols), 400

            # Display Total value and sell button option
            total_shares = db.execute(
                "SELECT shares FROM portfolio WHERE user_id = ? AND symbol = ?", session["user_id"], symbol)[0]["shares"]
            if shares > total_shares:
                return render_template("sell.html", error="You don't have enough shares to sell"), 400

            total_sale = shares * stock_info["price"]
            # Updating databases
            # Updating user's cash
            db.execute("UPDATE users SET cash = cash + ? WHERE id = ?",
                       total_sale, session["user_id"])

            # Updating user's portfolio
            new_shares = total_shares - shares
            if new_shares == 0:
                db.execute("DELETE FROM portfolio WHERE user_id = ? AND symbol = ?",
                           session["user_id"], symbol)
            else:
                db.execute("UPDATE portfolio SET shares = ? WHERE user_id = ? AND symbol = ?",
                           new_shares, session["user_id"], symbol)

            # Updating transactions history
            now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            db.execute("INSERT INTO history (user_id, symbol, shares, price, type, date) VALUES (?, ?, ?, ?, 'SELL', ?)",
                       session["user_id"], symbol, shares, stock_info["price"], now)

            flash(
                f"Congratulations! You sold {shares} shares of {stock_info["name"]} for {usd(total_sale)}", "success")
            return redirect("/")


@app.route("/new_password", methods=["GET", "POST"])
def new_password():
    if request.method == 'GET':
        return render_template("new_password.html")

    if request.method == 'POST':
        username = request.form.get("username")
        if not username:
            return render_template("new_password.html", error="Missing username", username=username), 400

        # Checking existed user
        existed_user = db.execute(
            "SELECT username, id FROM users WHERE LOWER(username) = LOWER(?)", username)
        if not existed_user:
            return render_template("new_password.html", error="That's not a registered user", username=username), 400
        existed_user_username = existed_user[0]["username"]
        existed_user_id = existed_user[0]["id"]

        # Checking if security answer is correct
        security_answer = request.form.get("security_answer")
        if not security_answer:
            return render_template("new_password.html", error="Missing security answer", username=username), 400
        security_answer = security_answer.lower()

        try:
            stored_security_answer = db.execute(
                "SELECT answer_hash FROM security WHERE user_id = ?", existed_user_id)[0]["answer_hash"]
        except IndexError:
            return render_template("new_password.html", error="Security answer not found. Try again or contact support for help.", username=username), 400
        if not check_password_hash(stored_security_answer, security_answer):
            return render_template("new_password.html", error="That's not the correct answer! Security Question: What's the first name of your mother?", username=username), 400

        session["reset_username"] = existed_user_username
        return redirect("/new_password_2")


@app.route("/new_password_2", methods=["GET", "POST"])
def new_password_2():
    if request.method == 'GET':
        if not session.get("reset_username"):
            return render_template("new_password_2.html", error="Expired session. Try again"), 400
        return render_template("new_password_2.html")

    if request.method == 'POST':
        username = session.get("reset_username")
        if not username:
            return render_template("new_password_2.html", error="Expired session. Try again"), 400

        password = request.form.get("password")
        if not password:
            return render_template("new_password_2.html", error="Missing password"), 400
        if len(password) < 8:
            return render_template("new_password_2.html", error="Password must have at least 8 characters"), 400

        confirmation = request.form.get("confirmation")
        if not confirmation:
            return render_template("new_password_2.html", error="Confirm your password"), 400

        if password != confirmation:
            return render_template("new_password_2.html", error="Passwords don't match"), 400

        # Checking if user is trying to use current password as the new one
        used_password = db.execute(
            "SELECT hash FROM users WHERE LOWER(username) = LOWER(?)", username)[0]["hash"]
        if used_password and (check_password_hash(used_password, password)):
            return render_template("new_password_2.html", error="You are already using that password. Try a different one."), 400

        # Changing password in the database
        hash_password = generate_password_hash(password)
        db.execute("UPDATE users SET hash = ? WHERE LOWER(username) = LOWER(?)",
                   hash_password, username)

        session.pop("reset_username", None)
        flash("Password successfully changed!", "success")
        return redirect("/password_changed")


@app.route("/password_changed")
def password_changed():
    return render_template("password_changed.html")


@app.route("/money", methods=["GET", "POST"])
@login_required
def money():
    cash = g.user["cash"]
    if request.method == 'GET':
        return render_template("money.html", username=g.user["username"], cash=cash)

    if request.method == 'POST':
        added_money = request.form.get("money")
        if not added_money:
            return render_template("money.html", error="Enter a value"), 400

        try:
            added_money = int(added_money)
            if added_money < 1 or added_money > 10000:
                return render_template("money.html", error="Insert a value between $1 and $10,000"), 400
        except ValueError:
            return render_template("money.html", error="That's not a valid value"), 400

        # Checking daily limit (with new table 'money')
        date = datetime.now().strftime("%Y-%m-%d")
        daily_money = db.execute("SELECT SUM(amount) AS daily_money FROM money WHERE user_id = ? AND date = ?",
                                 session["user_id"], date)[0]["daily_money"] or 0

        if daily_money + added_money > 10000:
            return render_template("money.html", error=f"You can only add $10,000 per day. You've already added {usd(daily_money)} today!"), 400

        # Updating the database
        # Updating user's daily limit
        now = datetime.now().strftime("%Y-%m-%d")
        db.execute("INSERT INTO money (user_id, amount, date) VALUES (?, ?, ?)",
                   session["user_id"], added_money, now)
        # Updating user's cash
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", added_money, session["user_id"])

        user_money = db.execute("SELECT cash FROM users WHERE id = ?",
                                session["user_id"])[0]["cash"]
        flash(
            f"You successfully added {usd(added_money)}! Now you have {usd(user_money)} in your account!")
        return redirect("/")


"""
TODO: add currency change (USD/BRL/EUR)
TODO: add light/dark them (see 'homepage' from pset8)
TODO: add options in table to allow user sort rows based on his preferences
"""
