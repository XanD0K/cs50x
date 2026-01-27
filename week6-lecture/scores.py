# week 2
"""
Functions
https://docs.python.org/3/library/stdtypes.html#sequence-types-list-tuple-range
len -> length of a list
"""



from cs50 import get_int

scores = [] # empty list

for i in range(3):
    score = get_int("Score: ")
    scores.append(score) #at the end of list
# Instead of 'scores.append', it is possible to use scores += [score]. It will add 2 lists
average = sum(scores) / len(scores)

print(f"Average: {average}")
