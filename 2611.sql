select movies.id,movies.name from movies
where movies.id_genres in (select genres.id from genres where genres.description = 'Action')
