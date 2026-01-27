from flask import Flask, render_template, request

app = Flask(__name__)
# '__name__' is a special variable in Python that literaly refers to the current file's name

@app.route("/")
def index():
    # return "hello, world"
    # return '<!DOCTYPE html><html lang="en"><head><title>hello, title</title></head><body>hello, body</body></html>'
    # html = render_template("index.html")
    # return html
    # if "name" in request.args:
    #     name = request.args["name"]
    # else:
    #     name = "world"
    # return render_template("index.html", placeholder=name)
    name = request.args.get("name", "world")
    return render_template("index.html", placeholder=name)


# Terminal: 'pip install -r requirements.txt'
# If Flask is not already installed, it will install in the system
# Finally, in terminal: flask run
# The function 'app.route' defines a route for the application
# You can make it print something in the screen (return 1).
# You can pass the whole HTML code to that (return 2).
# You can pass a file as reference which contains the HTML (return 3). For that, use import 'render_template'
# 'render_template' is a function specific to Flask, that opens a HTML file and send it from server to browser
# Python knows it must be in a 'templates' folder

# To use a placeholder, also import 'request', a special object that gives access to all of the HTTP parameters, the user input in the HTTP request that's causing the code to be executed
# name = request.args["name"]
# 'request.args' is a special variable that automatically stores all of the key value pairs via a Python dictionary
# 'placeholder=name' the second parameter
# The new URL is https://special-memory-p45766j7rr5fvpj-5000.app.github.dev/?name=Alex, with '?name=Alex' at the end
# That if/else condition allows user to access the default URL, without the '?name=Alex' key-value pair
# change 'placeholder'in HTML to be 'name', and use 'name=name' here

# Fourth option (return 4) changes the if-else conditon
# 'get' is a function that get the valur of a key. If doesn't find "name", you can specify a defaul value ('world')
