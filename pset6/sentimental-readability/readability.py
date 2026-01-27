text = input("Text: ")

letter_count = 0
word_count = 1  # Start with '1' to include last word
sentence_count = 0

# Iterates through all text
for i in range(len(text)):
    # Counting letters
    if text[i].isalpha() == True:
        letter_count += 1
    # Counting words
    elif text[i] == ' ':
        word_count += 1
    # Counting sentences
    elif text[i] == '.' or text[i] == "!" or text[i] == "?":
        sentence_count += 1

HUNDRED_WORDS = 100
CONST1 = 0.0588
CONST2 = 0.296
CONST3 = 15.8

# Letters per 100 words
letters_per_words = letter_count / word_count * HUNDRED_WORDS
# Sentences per 100 words
sentences_per_words = sentence_count / word_count * HUNDRED_WORDS

# Coleman-Liau formula
coleman_liau_index = (CONST1 * letters_per_words) - (CONST2 * sentences_per_words) - CONST3
# Rounded value to define the exact grade
rounded_grade = round(coleman_liau_index)

if rounded_grade < 1:
    print("Before Grade 1")
elif rounded_grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {rounded_grade}")


# TODO: code considering multiple consecutives spaces and ponctuation between words ('Mr.' or '3.14')
