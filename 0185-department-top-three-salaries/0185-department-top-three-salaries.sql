# Write your MySQL query statement below
with new_table as(
select
    d.name as Department,
    e.name as Employee,
    e.salary as Salary,
    DENSE_RANK() OVER(partition by d.name order by e.salary desc) as ranking
from Employee e
LEFT JOIN Department d 
ON e.departmentID = d.id
)
Select Department,Employee, Salary
from new_table
where ranking <=3;