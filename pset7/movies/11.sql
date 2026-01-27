SELECT title FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE movie_id IN
 (SELECT movie_id FROM stars WHERE person_id IN
  (SELECT id FROM people WHERE name = 'Chadwick Boseman'))
ORDER BY rating DESC
LIMIT 5;


--ANOTHER WAY
--SELECT title FROM movies, stars, people, ratings
--WHERE movies.id = ratings.movie_id
--AND ratings.movie_id = stars.movie_id
--AND stars.person_id = people.id
--AND name = 'Chadwick Boseman'
--ORDER BY rating DESC
--LIMIT 5;
