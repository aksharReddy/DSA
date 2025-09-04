# Write your MySQL query statement below
select f.name as Customers 
from Customers f
where f.id not in(

select c.id
from Customers c
join Orders o
ON c.id = o.customerid
)