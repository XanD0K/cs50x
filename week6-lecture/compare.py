# week1

from cs50 import get_int

x = get_int("What's x? ")
y = get_int("What's y? ")

if x < y:
    print("x is less than y")
elif x > y: # In Python, we use 'elif' instead of 'else if'
    print("x is greater than y")
else:
    print("x is equal to y")

# week4 - COmpare strings

s = input("s: ")
t = input("t: ")

if s == t:
    print("Same")
else:
    print("Different")
