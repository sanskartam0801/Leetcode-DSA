# Write your MySQL query statement below
SELECT product_name , year , price
FROM Sales as s
JOIN Product as p
WHERE p.product_id = s.product_id
