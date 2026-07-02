# Write your MySQL query statement below
select id,
SUM(IF (month="Jan", revenue , null)) AS Jan_Revenue,
SUM(IF (month = "Feb", revenue, null)) as Feb_Revenue,
SUM(if(month = "Mar", revenue, null)) as Mar_Revenue,
SUM(if (month = "Apr", revenue, null)) as Apr_Revenue,
sum(if(month="May", revenue, null)) as May_Revenue,
SUM(IF (month="Jun", revenue , null)) AS Jun_Revenue,
SUM(IF (month = "Jul", revenue, null)) as Jul_Revenue,
SUM(if(month = "Aug", revenue, null)) as Aug_Revenue,
SUM(if (month = "Sep", revenue, null)) as Sep_Revenue,
sum(if(month="Oct", revenue, null)) as Oct_Revenue,
SUM(if (month = "Nov", revenue, null)) as Nov_Revenue,
sum(if(month="Dec", revenue, null)) as Dec_Revenue

from Department
group by id;
