while True:
    try:
        height = int(input("Provide height between 1 and 8: "))
        if height >= 1 and height <= 8:
            break
    except ValueError:
        print("Provide a valid number between 1 and 8")

for _ in range(height):
    print(" " * (height - _ - 1), "#" * (_ + 1), sep='')
