from cs50 import SQL
from flask import Flask, render_template, redirect, request, session
from flask_session import Session

# Configure app
app = Flask(__name__)

# Connect to database
db = SQL("sqlite:///store.db")

# Configure session
app.config["SESSION_PERMANTEN"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


@app.route("/")
def index():
    books = db.execute("SELECT * FROM books") # db.execute return a list of dictionaries
    return render_template("books.html", books=books)
    


@app.route("/cart", methods=["GET", "POST"])
def cart():
    # Ensure cart exists
    if "cart" not in session:
        session["cart"] = []

    # POST
    if request.method == "POST":
        book_id = request.form.get("id")
        if book_id:
            session["cart"].append(book_id)
        return redirect("/cart")

    # GET
    books = db.execute("SELECT * FROM books WHERE id IN (?)", session["cart"])
    return render_template("cart.html", books=books)


"""
The cart is only stored in the session. They are not beein stored in a database
In the store/ directory, there's a new folder "flask_session/"
In this folder there are cookie values that are keeping track of what the user has been doing on the website
These files are the result of having  configured the session as:
app.config["SESSION_PERMANTEN"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

? is the placeholder for a value
(?) is the placeholder for a list
"""
