from cs50 import SQL
from flask import Flask, render_template, request

app = Flask(__name__)

db = SQL("sqlite:///froshims.db")


SPORTS = [
    "Basketball",
    "Soccer",
    "Ultimate Frisbee",
]

# REGISTRANTS = {}
# It's the same as saying REGISTRANTS = dict()
# Won't be needed anymore since we'll start storying all data in a SQL database

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)


@app.route("/register", methods=["POST"])
def register():

    name = request.form.get("name")
    if not name:
        return render_template("error.html", message="Missing name")

    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", message="Missing sport")
    if sport not in SPORTS:
        return render_template("error.html", message="Invalid sport")

    """
    checking the options in the checkbox input
    for sport in request.form.getlist("sport")
        if sport not in SPORTS:
            return tender_template("failure.html")
    """


    # REGISTRANTS[name] = sport
    # Won't be needed anymore

    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)

    return render_template("success.html")


@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT name, sport FROM registrants")
    return render_template("registrants.html", registrants=registrants)
# first registrants is the variable beng passed into the template
# second registrants is the value thereof


# All those 'if' conditions are there to prevent malicious users.

# SPORST is a global variable containing all allowed sports.
# It wil lserve as a server side validation

# REGISTRANTS is a dictionary that will store names and sports
# just by saying 'REGISTRANTS[name] = sport', we're allowing one name to overwrite another identical name


# db = SQL("sqlite:///froshims.db")
# That's how you, from Python, can talk to that SQL database
