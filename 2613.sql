select movies.id,movies.name from movies
where movies.id_prices in (select prices.id from prices where prices.value<2.00)
