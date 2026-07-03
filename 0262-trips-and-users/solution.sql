# Write your MySQL query statement below
select 
request_at as Day,
ROUND(SUM(status != 'completed')/ COUNT(status),2) as 'Cancellation Rate' FROM Trips
WHERE request_at BETWEEN '2013-10-01' and '2013-10-03'
and driver_id NOT IN (
    select users_id from Users 
    where banned = 'Yes'
)
and client_id NOT IN (
    select users_id from Users
    where banned = 'Yes'
)
group by Day
