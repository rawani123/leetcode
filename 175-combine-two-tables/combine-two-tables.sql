# Write your MySQL query statement below
Select firstName,lastName,city,state
FROM Person p 
LEFT JOIN Address a
ON p.personId = a.personId