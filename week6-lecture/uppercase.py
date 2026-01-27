# week2

"""
for loops in Python
for i in range(3):
    print("meow")
"""

before = input("Before: ")
print("After:  ", end="")
for c in before:
    print(c.upper(), end="")
print()

# another way
before = input("Before: ")
print("After:  ", end="")
print(before.upper(), end="")
print()

# another way
before = input("Before: ")
after = before.upper()
print(f"After:  {after}")

# another way
before = input("Before: ")
print(f"After:  {before.upper()}")
