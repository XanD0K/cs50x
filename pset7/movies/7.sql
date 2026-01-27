SELECT title, rating FROM movies
 JOIN ratings ON movies.id = ratings.movie_id
 WHERE year = 2010
 ORDER BY rating DESC, title ASC;

--Another way
--SELECT title, rating FROM movies, ratings
-- WHERE movies.id = ratings.movie_id
-- AND year = 2010
-- ORDER BY rating DESC, title ASC;
