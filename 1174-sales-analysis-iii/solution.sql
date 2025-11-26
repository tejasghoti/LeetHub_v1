# Write your MySQL query statement below
/*
select p.product_id, p.product_name from Product p
where p.product_id IN(
select product_id from sales
group by product_id
having MIN(sale_date) >= '2019-01-01' and MAX(sale_date) <= '2019-03-31'
)
*/
 select p.product_id, p.product_name from product p
 join  sales s on p.product_id=s.product_id
 group by p.product_id, p.product_name
 having min(s.sale_date)>='2019-01-01' and 
        max(s.sale_date)<='2019-03-31'


