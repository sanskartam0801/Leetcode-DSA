select d.name as Department, e1.name as Employee, e1.salary as Salary
from employee e1
join department d on e1.departmentId = d.id
where 3 > (
    select count(distinct e2.salary)
    from employee e2
    where e2.departmentId = e1.departmentId and e2.salary > e1.salary
);
