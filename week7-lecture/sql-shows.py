# IMDb (Internet Movie Database)

# SELECT COUNT(*) FROM shows;
# SELECT * FROM shows LIMIT 10;
# .schema shows

# sqlite> .schema shows
# CREATE TABLE shows (
#     id INTEGER,
#     title TEXT NOT NULL,
#     year NUMERIC,
#     episodes INTEGER,
#     PRIMARY KEY(id)
# );

# sqlite> .schema ratings
# CREATE TABLE ratings (
#     show_id INTEGER NOT NULL,
#     rating REAL NOT NULL,
#     votes INTEGER NOT NULL,
#     FOREIGN KEY(show_id) REFERENCES shows(id)
# );

# That last line in 'ratings' shows a relationship between the two tables
## The 'PRIMARY KEY' ia unique identifier for a table's row
## The 'FOREIGN KEY' is the appearance of the 'PRIMARY KEY' in other table

# DATA TYPES
## BLOB -> Binary Large Object -> storying 0's and 1's in the database
## INTEGER -> simple numbers
## NUMERIC -> dates, years, times
## REAL -> floating point values
## TEXT -> just text

#KEY WORDS
## NULL / NOT NULL -> allows to especify, when creating a table, what kind of values can or cannot be there
## UNIQUE -> avoid duplicates
## PRIMARY KEY
## FOREIGN KEY


# QUERYING
# SELECT * FROM ratings WHERE rating >= 6.0 LIMIT 10;
# SELECT show_id FROM ratings WHERE rating >= 6.0 LIMIT 10;
# SELECT * FROM shows WHERE id IN (SELECT show_id FROM ratings WHERE rating >= 6.0) LIMIT 10;
## That's the same as:
### SELECT * FROM shows WHERE id IN -> Without the ';'
#### (SELECT show_id FROM ratings WHERE rating >= 6.0)
#### LIMIT 10;
# SELECT title FROM shows WHERE id IN (SELECT show_id FROM ratings WHERE rating >= 6.0 LIMIT 10); -> gets the title

# JOIN -> Allows to join 2 or more tables together
# SELECT * FROM shows JOIN ratings ON shows.id = ratings.show_id WHERE rating <= 6.0 LIMIT 10;
## It's now selecting from 2 tables ('shows' and 'rating')
## And how those 2 tables should be lined up? The 'id' in one with the 'show_id' in the other
# SELECT title, rating FROM shows JOIN ratings ON shows.id = ratings.show_id WHERE rating <= 6.0 LIMIT 10;
## Shows only 'title' an 'rating' columns


# SELECT * FROM genres LIMIT 10; -> But it has duplicates
"""
+---------+-----------+
| show_id |   genre   |
+---------+-----------+
| 62614   | Comedy    |
| 63881   | Adventure |
| 63881   | Comedy    |
| 63881   | Family    |
| 63962   | Action    |
| 63962   | Sci-Fi    |
| 65269   | Family    |
| 65269   | Fantasy   |
| 65270   | Comedy    |
| 65270   | Sci-Fi    |
+---------+-----------+
"""
### It's a missed oportunity to normalize those tables by removing duplicates and having a whole separate table (like shows and people)
# SELECT * FROM shows WHERE id = 63881;
# SELECT genre FROM genres WHERE show_id = 63881; -> Selecting genres from Catweazle
# SELECT id FROM shows WHERE title = 'Catweazle'; -> Getting Catweazle's ID
# SELECT genre FROM genres WHERE show_id = (SELECT id FROM shows WHERE title = 'Catweazle');
## Use 'IN' when searching across multiple values
## Use '=' when you know there's just to be 1
# SELECT * FROM shows JOIN genres ON shows.id = genres.show_id WHERE id = 63881;
## SELECT title, genre  FROM shows JOIN genres ON shows.id = genres.show_id WHERE id = 63881;

# SELECT title FROM shows where id IN
## (SELECT show_id FROM genres WHERE genre = 'Comedy' LIMIT 10); -> 10 comedies shows


# many-to-many relationship
# SELECT * FROM shows WHERE title = 'The Office';
# SELECT * FROM shows WHERE title = 'The Office' AND year = 2005;
## Want to know the stars from that show. Baby steps:
# SELECT id FROM shows WHERE title = 'The Office' AND year = 2005; -> Getting it's ID
## SELECT person_id FROM stars WHERE show_id = (
### SELECT id FROM shows WHERE title = 'The Office' AND year = 2005);
#### But that will only show the stars's ID
### SELECT name FROM people WHERE id IN
#### (SELECT person_id FROM stars WHERE show_id =
#### (SELECT id FROM shows WHERE title = 'The Office' AND year = 2005));

# Searchingfor all shows that Steve Carell was in
# SELECT title FROM shows WHERE id IN
## (SELECT show_id FROM stars WHERE person_id =
## (SELECT id FROM people WHERE name = 'Steve Carell'));
# Another approach
## SELECT title FROM shows
### JOIN stars ON shows.id = stars.show_id
### JOIN people ON stars.person_id = people.id
### WHERE name = 'Steve Carell';
# Another approach
## SELECT title FROM shows, stars, people
### WHERE shows.id = stars.show_id
### AND people.id = stars.person_id
### AND name = 'Steve Carell';


# INDEXES
# Data structure that makes it faster to perform queries
# # .timer ON -> counts how many seconds it takes to run commands
# CREATE INDEX name ON table (column, ...);
# SELECT * FROM shows WHERE title = 'The Office'; -> Took 0.043 seconds
# CREATE INDEX title_index ON shows(title);
# SELECT * FROM shows WHERE title = 'The Office'; -> Now it took 0.001 seconds
# That index creates a B-tree, a structure to speed up the time to get from the root node at the top to the leaf node at the bottom
# Downside is that those B-trees need more space in memory or on the server's hard drive
# PRIMARY KEYs are always constant. They are automatically indexed

# SELECT title FROM shows, stars, people
## WHERE shows.id = stars.show_id
## AND people.id = stars.person_id
## AND name = 'Steve Carell';
### That took 2.967 seconds

# SELECT title FROM shows WHERE id IN
## (SELECT show_id FROM stars WHERE person_id =
## (SELECT id FROM people WHERE name = 'Steve Carell'));
### That took 0.198 seconds

# To speed up, let's create indexes
## CREATE INDEX show_index ON stars (show_id);
## CREATE INDEX person_index ON stars (person_id);
## CREATE INDEX name_index ON people (name);
# Now, those previous commands took 0.001 seconds
