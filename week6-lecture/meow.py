i = 0
while i < 3:
    print("meow")
    i += 1

# another way
for i in [0, 1, 2]:
    print("meow")

# another way

for i in ["cat", "dog", "bird"]:
    print("meow")

# another way
for _ in range(3): # If you just gonna do something 3 times its usual to call that variable '_'
    print("meow")


# another way
# In Python, there is no need for a 'main' function.
# But if you're defining your own functions, you might implement a 'main' function (it doesn't need to be called 'main')
# If you do this, you need to call the 'main' function
def main():
    for _ in range(3):
        meow()

def meow(): # Definig a function
    print("meow")

main()

# another way (now meow() takes an argument)
def main():
    meow(3)

def meow(n): # Definig a function
    for i in range(n):
        print("meow")

main()

# The conventional way to call main
if __name__ == "__main__":
    main()
