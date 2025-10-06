CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
        SELECT DISTINCT salary
        FROM (
            select salary, dense_rank() over(order by salary desc) as ranked from employee
        ) as temp_table
        where ranked = N

  );
END