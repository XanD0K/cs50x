import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session


# Configure application
app = Flask(__name__)

# Setting up a key to for 'flash'
app.secret_key = os.urandom(24)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():

    if request.method == "POST":
        # TODO: Add the user's entry into the database
        # Access form data
        name = request.form.get("name")
        if not name:
            flash("Missing name", "name_error")
            return redirect("/")

        month = request.form.get("month")
        if not month:
            flash("Missing month", "month_error")
            return redirect("/")
        try:
            month = int(month)
        except ValueError:
            flash("Please, insert a number for the month value", "month_error")
            return redirect("/")
        if month < 1 or month > 12:
            return redirect("/")
        day = request.form.get("day")
        if not day:
            flash("Missing day", "day_error")
            return redirect("/")
        try:
            day = int(day)
        except ValueError:
            flash("Please, insert a number for the day value", "day_error")
            return redirect("/")
        if day < 1 or day > 31:
            flash("That's not a valid day", "day_error")
            return redirect("/")

        # Other validations
        if month in [4, 6, 9, 11] and day > 30:
            flash("That's not a valid day", "day_error")
            return redirect("/")
        if month == 2 and day > 29:
            flash("That's not a valid day", "day_error")
            return redirect("/")


        # Insert data into database
        db.execute("INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?)", name, month, day)

        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        # Query for all birthdays
        birthdays = db.execute("SELECT * FROM birthdays")

        # Return birthdays page
        return render_template("index.html", birthdays=birthdays)


@app.route("/deregister", methods=["POST"])
def deregister():

    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM birthdays WHERE id = ?", id)
    return redirect("/")
