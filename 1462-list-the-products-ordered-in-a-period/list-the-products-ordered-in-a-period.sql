# Write your MySQL query statement below
SELECT product_name, SUM(unit) AS unit 
FROM Products
JOIN orders
ON Products.product_id = orders.product_id
WHERE MONTH(order_date)=2 AND YEAR(order_date)=2020
GROUP BY Products.product_id
HAVING unit>=100;