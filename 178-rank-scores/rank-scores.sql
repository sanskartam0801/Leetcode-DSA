# Write your MySQL query statement below
select score , DENSE_RANK() OVER (ORDER BY score DESC) as 'Rank' from Scores 