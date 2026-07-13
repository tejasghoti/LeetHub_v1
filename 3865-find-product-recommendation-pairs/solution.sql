-- Write your PostgreSQL query statement below
WITH filter_first AS(
SELECT product_id, count(user_id) total_bought
FROM ProductPurchases
GROUP BY product_id
HAVING count(user_id) > 2
)
, second_process AS(
SELECT P.*, PR.category 
FROM ProductPurchases P
INNER JOIN ProductInfo PR ON P.product_id = PR.product_id
WHERE EXISTS ( SELECT 1 FROM filter_first F WHERE P.product_id = F.product_id)
)
, third_process AS(
SELECT product_id, category, '-' || string_agg(CAST(user_id AS VARCHAR(10)),'-') || '-' list_user
FROM second_process S
GROUP BY product_id,category
ORDER BY product_id
)
SELECT p.product_id AS product1_id  , sub.product_id AS product2_id , p.category AS product1_category , sub.category AS product2_category ,  COUNT(position) customer_count
FROM  second_process P LEFT JOIN LATERAL (
	SELECT *,POSITION( ('-' || CAST(P.user_id AS VARCHAR(10)) || '-') IN T.list_user)
	FROM third_process T 
	WHERE T.product_id > P.product_id
	AND POSITION( ('-' || CAST(P.user_id AS VARCHAR(10)) || '-') IN T.list_user) > 0
	
)sub ON 1 = 1
GROUP BY p.product_id, sub.product_id, p.category, sub.category
HAVING COUNT(position) > 2
ORDER BY customer_count DESC, product1_id, product2_id
