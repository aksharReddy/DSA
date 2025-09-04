# Write your MySQL query statement below
-- select f.name as Customers 
-- from Customers f
-- where f.id not in(

-- select c.id
-- from Customers c
-- join Orders o
-- ON c.id = o.customerid
-- )

select c.name as Customers
from Customers c
left join Orders o
ON c.id = o.customerId
where o.customerId is null