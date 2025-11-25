# Write your MySQL query statement below
select * from Cinema
# also can write where id % 2 = 1 AND ...
where mod(id, 2) = 1 AND description not like 'boring'
order by rating desc;



