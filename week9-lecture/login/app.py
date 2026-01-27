from flask import Flask, render_template, redirect, request, session
from flask_session import Session

app = Flask(__name__)

# Turning cookies on for this web application
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app) # Turns on "Sessions"
# For all this to work, need to add the 'Flask-Session' requirement


@app.route("/")
def index():
    return render_template("index.html", name=session.get("name"))


@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        session["name"] = request.form.get("name") # Storing the name in the session
        return redirect("/")

    return render_template("login.html")


@app.route("/logout")
def logout():
    session.clear()  # Forget user's name, items, all contents of the session
    return redirect("/")


# To remember that a user logged into a website, we'll use a 'session'.
# 'Session' is a word that describes the maintenance of state between a client and a server.
# If the server remember something about you, you have a session with that server

# 'session' is a feature of Flask built on top of cookies
# 'redirect' function allows to redirect the user to anotehr page

# The session global variable allows you to to store something in memory for a specific user using the session dictionary instead of in a global variable, instead of in database
# Using registrants (like we did in 'frosh_ims.html'), every user of the website would have access to that memory
# Using 'session' is a per user variable
