# Write your MySQL query statement below
with cte AS 
(Select num
FROM MyNumbers
GROUP BY num
HAVING COUNT(num)=1)


SELECT CASE WHEN Count(*)>0 THEN MAX(num)
ELSE NULL END AS num
FROM cte