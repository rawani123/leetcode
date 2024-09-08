# Write your MySQL query statement below
SELECT score, DENSE_RANK() OVER(ORDER BY SCORE DESC) as "rank" FROM SCORES