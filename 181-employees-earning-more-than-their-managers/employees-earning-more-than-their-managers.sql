# Write your MySQL query statement below
Select e1.name AS Employee
From Employee e1
LEFT JOIN Employee e2
ON e1.managerId = e2.id
WHERE e1.salary>e2.salary