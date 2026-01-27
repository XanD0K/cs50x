"""
https://www.example.com/
The last '/' is referring to a specific file that has been configured on the server to be the default page
You can also specify specific files or folders with '/file.html' or ' /folder' or even '/folder/file.html'
'/path' refers to everthing (files and folders) after the TLD ('.com') that the browser is requesting
Those files and folders don't need to exist. With Python, you can specify specifics paths that don't actually exist in your codespace,
but hey represent a resource (URL) that you want to be able to access via your browser
'/route' generically means the path you want to select on a web server
'/route?key=value&key=value' Once you configured a route in code, you can even specify that that route takes user input

FLASK
Is a very popular micro framework in the world of Python, a small library
It reads inside the virtual envelops, figuring out what web page or route is requested and exactly what keys and values were passed in
Now, intead of using 'http-server', which is a command that only serves up static content, we will use 'flask run'
Not only 'flask' is a library, but also a command. It will still start a web server, but will execute your Python code to generate those web pages dynamically
We gonna need typically at least 2 files:
'app.py'
'requirements.txt' -> You specify all libraries that you want the web application to use
Each of these files, in conjunction, will be understood by that flask command
Here, in Python, while using the Flask framework, is how we might implement the simplest of web applications:

from flask import Flask

app = Flask(__name__)

@app.route("/")
def index():
    return "hello, world"


"app = Flask(__name__)" says to Flask: "turns this file into a web application and let me refer to it via a variable called 'app'"
'__name__' is a special variable that refers to the name of the current file

"@app.route("/")" says to Flask: "please turn the following function into a route so that can be served up by the server to a browser"
@ is a Decorator. It allows you to wrap one function inside of another
The function is 'index()', but it can be called anything you want, but index makes sence if this meant to be the index of the website
The argument to the app.route function ("/") tells flaks whenever the user visits like 'example.com/', please call this function and send to the browser whatever this function returns

OBS: In Python, besides Flask, you can use other other frameworks like Django, and there's many others in many other languages
"""
