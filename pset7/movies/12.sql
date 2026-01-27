SELECT title FROM movies WHERE id IN
 (SELECT movie_id FROM stars WHERE person_id =
  (SELECT id FROM people WHERE name = 'Bradley Cooper'))
 AND id IN (SELECT movie_id FROM stars WHERE person_id =
  (SELECT id FROM people WHERE name = 'Jennifer Lawrence'));

--ANOTEHR WAY
--SELECT title FROM movies, stars AS star1, people AS person1, stars AS star2, people AS person2
--WHERE movies.id = star1.movie_id
--star1.person_id = person1.id
--movies.id = star2.movie_id
--star2.person_id = person2.id
--person1.name = 'Bradley Cooper'
--person2.name = 'Jennifer Lawrence';

--ANOTHER WAY
--SELECT title FROM movies
--JOIN stars AS star1 ON movies.id = star1.movie_id
--JOIN people AS person1 ON star1.person_id = person1.id
--JOIN stars AS star2 ON movies.id = star2.movie_id
--JOIN people AS person2 ON star2.person_id = person2.id
--WHERE person1.name = 'Bradley Cooper'
--AND person2.name = 'Jennifer Lawrence';
