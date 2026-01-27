# use .py to code a program in python
# use python program.py to run that program (python works as './' in C)

print("Hello, world")

# Use 'import cs50' in Python to import cs50 library
# It's possible to import specific thing using 'from cs50 import get_string'

from cs50 import get_string

answer = get_string("What's your name? ")
print("hello, " + answer)
print("hello, style50 hello.py", answer)
print(f"hello, {answer}") # the 'f' says it is a formatted string

"""
Python documentation"
print(*objects, sep=' ', end='\n', file=None, flush=False)"
First one is a "positional paramether"
*objects -> you can pass 0 or more
All other are "named parameters"
sep=' ' -> automatically gives a "free space" between arguments
end='\n' -> automatically moves to the next line
"""

print("Hello, world", end="!\n")

# In Python there are data types, but you don't have to declare them
# Data types in Python: bool, floar, int, str
# There is no 'long', no 'double' and no 'char' (...)
"""
Python already have data structures: "
'range', (gives a range of values)
'list', (automatically gives a linked list)
'tuple' (x,y values),
'dict' (dictionary),
'set' (for spell checker)
(...)
"""
