# SQL (Structured Query Language) is a declarative language where you declare the data that you want to get back
# CRUD (Create, Read, Update, Delete)
# Fisrt we need a database. And data in databases are stores in "tables"
# We'll work in the terminal
# In terminal: 'sqlite3 favorites.db'

# To load a csv file to SQL:
# .mode csv -> Puts SQL in csv mode
# .import favorites.csv favorites -> Imports a file called 'favorites.csv' to the dabatase 'favorites.db'. It stores inside the .db file a table called 'favorites'
# .quit -> quit the SQLite

# sqlite3 favorites.db -> opens the file again
# .schema -> shows the schema (the design) of the database
# SELECT * FROM favorites; -> Selects everything from the table. Let you READ everything in the database
# SELECT language FROM favorites LIMIT 10; -> Will show only the 10 first lines
# SELECT COUNT(*) FROM favorites; -> count the number of columns (not including the header)
# SELECT DISTINCT language FROM favorites; -> Will whittle down the language column without duplicate submitions
# SELECT COUNT(DISTINCT language) FROM favorites; -> Combine those 2 and count how many distict languages there are
# SELECT COUNT(*) FROM favorites WHERE language = 'C'; -> how many people liked C language
# SELECT COUNT(*) FROM favorites WHERE language = 'C' AND problem = 'Hello, World';
# SELECT COUNT(*) FROM "favorites" WHERE "language" = 'C' AND "problem" = 'Hello, World';
## single quotes for string literal (value that it's searching for)
## double quotes around the symbols from table name and column names, but it's now necessary
# SELECT COUNT(*) FROM favorites WHERE language = 'C' AND (problem = 'Hello, World' OR problem = 'Hello, It''s Me');
## 'Hello, It''s Me' -> double '' so that it understand that it's an ' and not the end of the program's name. In C, it would be \'
# SELECT COUNT(*) FROM favorites WHERE language = 'C' and problem LIKE 'Hello, %'; -> The '%' indicates the rest
# SELECT language, COUNT(*) FROM favorites GROUP BY language; -> Counts how many, from each language
# SELECT language, COUNT(*) FROM favorites GROUP BY language ORDER BY COUNT(*); -> Sorted by the count column
## ORDER BY COUNT(*) it's the same as ORDER BY COUNT(*) ASC. Use DESC for descending order
# SELECT language, COUNT(*) AS n FROM favorites GROUP BY language ORDER BY n DESC; -> give allias to the headers
# SELECT language, COUNT(*) AS n FROM favorites GROUP BY language ORDER BY n DESC LIMIT 1; -> The LIMIT function limits the number of exibited outputs

# INSERT INTO favorites (language, problem) VALUES ('SQL', 'Fiftyville'); -> Insert data in a table
# (...)
# | 10/15/2024 10:32:52 | Python   | Starting from Scratch |
# | 10/15/2024 10:32:53 | C        | Recover               |
# | NULL                | SQL      | Fiftyville            |
## In SQL, NULL represents explicitly the abscence of a  value

# DELETE FROM favorites WHERE Timestamp IS NULL; -> Will delete the NULL line above
## NEVER do: 'DELETE FROM favorites;' cuz it'll delete everything from that table!

# Update table SET column = value WHERE condition;
# UPDATE favorites SET language = 'SQL', problem = 'Fiftyville'; -> Abscence of 'WHERE' clause will change every cell of the table



# .mode -> check the display mode
# current output mode: table --wrap 0 --wordwrap off --noquote
# --wrap 0 means wrapping is disabled
# --wordwrap off -> combined with '--wrap 0' it ensures that each row stays on a single line, even if the data is lengthy
# .show -> shows the configuration of the 'mode'
# change settings and make it apply every time I open SQLite
# create a .sqliterc file in gome directorey with the commands:
# .mode column
# .headers on
# On Windows, you’d need to create the file in your user directory (e.g., C:\Users\YourUsername\.sqliterc) using a text editor
# On Linux/Mac, you can create this file with: echo -e ".mode column\n.headers on" > ~/.sqliterc
