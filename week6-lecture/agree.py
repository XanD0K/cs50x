#week 1

s = input("Do you agree? ")
if s == "Y" or s == "y":
    print("Agreed.")
elif s == "N" or s == "n":
    print("Not agreed.")

# another way
if s in ["Y", "y"]: # Mean: if 's' in a list of values
    print("Agreed.")
elif s in ["N", "n"]:
    print("Not agreed.")

# In python, instead of structures, we have objects
# Those objects are defined as "class", a blueprint/template out of which multiple objects can be made
# Method -> functions that are associated with a specific data type
# 'lower' is a method that comes with str

t = s.lower()
if t in ["y", "yes"]:
    print("Agreed.")
elif t in ["n", "no"]:
    print("Not agreed.")

#another way
s = s.lower()

s = input("Do you agree? ").lower()
