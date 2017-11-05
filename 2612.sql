select movies.id ,movies.name from movies where (movies.id_genres in
(select genres.id from genres where genres.description = 'Action'))
and (movies.id in 
(select movies_actors.id_movies from movies_actors 
where movies_actors.id_actors in
 (select actors.id from actors 
where (actors.name ='Marcelo Silva')
or(actors.name='Miguel Silva'))))
