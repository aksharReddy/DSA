# Write your MySQL query statement below

-- select e.email as Email
-- from person e
-- group by email
-- having count(e.email) > 1

select distinct e.email as Email
from person e
JOIN person p 
on e.email = p.email and e.id!=p.id