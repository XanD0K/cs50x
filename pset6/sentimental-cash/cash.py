while True:
    try:
        change = float(input("Change: "))
        if change >= 0:
            break
        else:
            print("Not a valid number!")
    except ValueError:
        print("Provide a valid value")

# Trasnforming the user's input in integer values
change = round(change * 100)
# Keep track of number of coins
coins = 0

for coin_value in [25, 10, 5, 1]:
    coins += (change // coin_value)
    change %= coin_value

print(coins)
