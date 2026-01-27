from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/greet", methods=["POST"])
def greet():
    name = request.form.get("name", "world")
    return render_template("greet.html", name=name)

# Using the new "greet.html! template will cause error 500 (Internal Error), which is the developer's fault
# There will be probably diagnostically useful hints in the terminal window
# "jinja2.exceptions.TemplateNotFound: greet.html"
# 'jinja' is a templating library, which purpose is to handle everything inside of that template's directory
# Beside "app.py", "requirements.txt" and "templates/", we'll also use the folder "static" to store images, JS files and CSS files

# To use 'post', we have to pass that method when creating the route
# Also, while 'get' parameters are stored in 'request.args', 'post' requests are stored in 'request.form'
