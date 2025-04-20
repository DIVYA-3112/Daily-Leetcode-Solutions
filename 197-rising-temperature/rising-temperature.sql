# Write your MySQL query statement below
-- select e1.id
-- from Weather as e1
-- join Weather as e2
-- on e1.id = e2.id - 1
-- where e1.temperature > e2.temperature;

select e1.id
from Weather as e1
join Weather as e2
on datediff(e1.recordDate, e2.recordDate) = 1
where e1.temperature > e2.temperature;