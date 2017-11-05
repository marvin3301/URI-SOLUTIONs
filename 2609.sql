SELECT c.name, SUM(p.amount) 
FROM categories c JOIN products p ON p.id_categories = c.id
group by c.name
