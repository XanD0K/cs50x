import csv

"""
with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)  # Makes a Dictionary from each key in the headers row
    scratch, c, python = 0, 0, 0

    for row in reader:
        favorite = row["language"]
        if favorite == "Scratch":
            scratch += 1
        elif favorite == "C":
            c += 1
        elif favorite == "Python":
            python += 1

print(f"Scratch: {scratch}")
print(f"C: {c}")
print(f"Python: {python}")
"""

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)  # Makes a Dictionary from each key in the headers row
    counts = {} # An empty dictionary
    for row in reader:
        favorite = row["language"]
        if favorite in counts: # "Is there a key with that name?"
            counts[favorite] += 1
        else:
            counts[favorite] = 1

for favorite in sorted(counts):  # 'sorted' sort the dictionary by key
    print(f"{favorite}: {counts[favorite]}")

print()  # New line

for favorite in sorted(counts, key=counts.get):  # now 'key' is the value in 'counts'
    print(f"{favorite}: {counts[favorite]}")

print()  # New line

for favorite in sorted(counts, key=counts.get, reverse=True):  # now 'it's reversed
    print(f"{favorite}: {counts[favorite]}")

print()  # New line


# Better way to do it
import csv

from collections import Counter

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)  # Makes a Dictionary from each key in the headers row
    counts = Counter()

    for row in reader:
        favorite = row["problem"]
        counts[favorite] += 1
"""
for favorite, count in counts.most_common():  # it's getting 2 variables at a time from counts. 'most_common'
    print(f"{favorite}: {counts[favorite]}")
"""
favorite = input("Favorite: ")
print(f"{favorite}: {counts[favorite]}")
