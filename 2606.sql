SELECT products.id,products.name 
FROM products 
WHERE  products.id_categories in
(select categories.id from categories where categories.name LIKE 'super%')
