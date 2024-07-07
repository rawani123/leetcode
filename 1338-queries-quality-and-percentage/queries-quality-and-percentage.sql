# Write your MySQL query statement below

with cte AS
(Select  query_name, rating/position AS ratio,CASE when rating < 3 
THEN 1 ELSE 0 END AS quality_binary
FROM Queries)


select query_name,ROUND(AVG(ratio),2) AS quality,ROUND((SUM(quality_binary)/COUNT(*))*100,2) as poor_query_percentage
 FROM cte 
 where query_name is not null
Group by query_name

