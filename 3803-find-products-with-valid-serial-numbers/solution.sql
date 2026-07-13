-- Write your PostgreSQL query statement below
SELECT *
FROM products
WHERE description ~ '(^|\s)SN[0-9]{4}\-[0-9]{4}($|[^0-9]+$)'
ORDER BY product_id
