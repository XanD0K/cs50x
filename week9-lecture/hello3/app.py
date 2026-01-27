# In this version we will use a single route
# It might not be desirable. It's just an example
# It might be useful for large web applications

from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        return render_template("greet.html", name=request.form.get("name"))
    else:
        return render_template("index.html")


"""
Jinja, thus far, allows us to:
- place values incide the curly praces {}
- do that block feature
We can also use it to create conditions for placeholders like in 'greet.html'
"""
