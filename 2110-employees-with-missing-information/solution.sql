# Write your MySQL query statement below
select e.employee_id from (
    select * from Employees 
    left join Salaries USING(employee_id)
    UNION
    select * from Employees
    right join Salaries USING(employee_id)
) as e
where e.name is null or e.salary is null
order by employee_id;
