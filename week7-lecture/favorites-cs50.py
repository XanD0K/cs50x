"""
from cs50 import SQL
db = SQL("sqlite:///favorites.db") # type: ignore

favorite = input("Favorite: ")

rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE language = ?", favorite)
# '?' is a placeholder vor a value, like '%s' in C
# 'SELECT' will output a list of 0 or more rows (one for every match)
# Each of the elements in that list of rows is going to be a dictionary.
# The keys for each of those dictionaries are going to be the name of the columns from SQL table

row = rows[0]  # Gets the first row

print(row["n"])
"""



# Race conditions
# The database is constatly beeing update (like likes of a viral photo)
## rows = db.execute("SELECT likes FROM posts WHERE id = ?", id);
## likes = rows[0]["likes"]
## db.execute("UPDATE posts SET likes = ? WHERE id = ?", likes +1, id);
# If things happens quickly, it might not compute all likes
# If you have code being executed that can get interrupted by other code beign executed on another server, it happens that "race condition"

# SQL can prevent this.
# 'Transaction' allows to say to the database "execute all of these queries, or none of them". It is not acceptable for part of them to get executed
# Key Features:
## BEGIN TRANSACTION
## COMMIT
## ROLLBACK

# The right way to do this:
# db.execute("BEGIN TRANSACTION")
# rows = db.execute("SELECT likes FROM posts WHERE id = ?", id);
# likes = rows[0]["likes"]
# db.execute("UPDATE posts SET likes = ? WHERE id = ?", likes +1, id);
# db.execute("COMMIT")


# SQL injection attacks
# "Prompt-injection attack" in AI
## People trying to trick AI into misbehaving in certain ways, by injecting inputs that they were not expecting
# In SQL injection attack, user try maliciously and cleverly use characters and ponctuations (for example in an email address to log in in a website) that are not
## valid email character, but they are valid SQL characters like sinque quotes (') or two dashes (--)
# In SQL, -- means the beggining of a comment
# So user try to enter the email malan@harvard.edu'--

# In Python:
# rows = db.execute(f"SELECT * FROM users WHERE username = '{username}' AND password = '{password}'")
# rows = db.execute(f"SELECT * FROM users WHERE username = 'malan@harvard.edu'--' AND password = '{password}'")
# That's why you don't use formated strings for SQL
# The right solution would be: rows = db.execute(f"SELECT * FROM users WHERE username = ? AND password = ?", username, password)

# Prevent someone's input to not only prevent --, but also DROP DATABASE TABLE
