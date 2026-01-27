# 'pip' allows to install third-party libraries
# 'pip install cowsay'

import cowsay

name = input("Name: ")
cowsay.cow(f"Hello, {name}")
