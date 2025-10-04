# Write your MySQL query statement below
select e2.name as Employee
from employee as e1
join employee as e2 
on e1.id = e2.managerId
where e1.salary < e2.salary