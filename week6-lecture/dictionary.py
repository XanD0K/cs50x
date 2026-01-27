# That's pset5 "Speller" in Python

words = set()


def check(word):
    return word.lower() in words


def load(dictionary):
    with open(dictionary) as file:
        words.update(file.read().splitlines())
        return True


def size():
    return len(words)

# In Pyrhon, you don't actually have to free memory
def unload():
    return True
