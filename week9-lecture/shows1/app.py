# Searches for shows

from cs50 import SQL
from flask import Flask, render_template, request, jsonify

app = Flask(__name__)

db = SQL("sqlite:///shows.db")


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/search")
def search():
    query = "%" + request.args.get("q") + "%"
    shows = db.execute("SELECT * FROM shows WHERE title LIKE ?", query)
    return render_template("search.html", shows=shows)

# In SQL, when using 'LIKE', we need to use special characters (wild card). That's the use of "%" in query

# Now, we're going to use JS to tweak the implementation of 'index.html' such that it still has a form,
# but it still has JS code that goes and fetches from the server any book titles that match user's input
# Rather than a submit button that send the whole form to the server and let the server generates all HTML, JS will allow a more client side
# Modifying 'search.html' route so that it behaves as an API (application programming interface), which is a way of standardizing how you provide input from a service and get output there from
# It's a way from getting data from someone else's server or service into your application
# This isn't the best way to do this. When it comes to API you shouldn't sending back snippets of HTML, but really raw data
