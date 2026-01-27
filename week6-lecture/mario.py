from cs50 import get_int

## Vertical blocks
# In Python there is no 'do while' loop
while True:
    n = get_int("Height: ")
    if n > 0:
        break

for i in range(n):
    print("#")

# if import the whole cs50 library, will get an error message
# solution is use 'n = cs50.get_int("Height: ")'


## Horizontal blocks
for i in range(4):
    print("#", end="")
print() # New line

# another way
print("#" * 4)



## 3x3 grid
for i in range(3):
    for j in range(3):
        print("#", end="")
    print()

# another way
for i in range(3):
    print("#" * 3)
