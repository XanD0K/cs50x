# week 3

names = ["Yuliia", "David", "John"]

name = input("Name: ")

for n in names:
    if name == n:
        print("Found")
        break
else: #else can be used with for loops
    print("Not found")

# another (better) way
if name in names: # search the name you are looking for in he list "names"
    print("Found")
else:
    print("Not found")
