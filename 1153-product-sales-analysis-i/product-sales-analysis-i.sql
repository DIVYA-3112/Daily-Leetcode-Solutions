# Write your MySQL query statement below
select e2.product_name, e1.year, price
from Sales as e1
left join Product as e2
on e1.product_id = e2.product_id;