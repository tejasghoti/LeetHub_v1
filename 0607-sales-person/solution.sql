# Write your MySQL query statement below

# my method
/*
select name from SalesPerson 
where sales_id NOT IN (
    SELECT DISTINCT o.sales_id
    From orders o
    join company c on o.com_id = c.com_id
    where c.name='RED'
);
*/

# better method
select s.name
from orders o
join company c on c.com_id = o.com_id and c.name = 'red'
right join salesperson s on s.sales_id = o.sales_id
where o.sales_id is null
