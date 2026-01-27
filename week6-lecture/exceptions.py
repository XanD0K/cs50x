a = input("Input a: ")
if a.isnumeric():
    print("Integer.")
else:
    print("Not integer.")

b = int(input("Input b: "))
if b == 0: # You are sacrificing the '0' value for 'm' variable.
    print("Not integer.")

# another way
try:
    n = int(input("Input n: "))
    print("Integer.") # It's bad design to put lots of thing in 'try' that aren't going to fail
except ValueError:
    print("Not integer.")

# better way
try:
    n = int(input("Input n: "))
except ValueError:
    print("Not integer.")
else:
    print("Integer.")
