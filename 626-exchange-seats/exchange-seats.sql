# Write your MySQL query statement below
SELECT 
    CASE 
        WHEN MOD(id, 2) = 1 AND EXISTS (SELECT 1 FROM Seat s2 WHERE s2.id = Seat.id + 1) THEN id + 1
        WHEN MOD(id, 2) = 0 AND EXISTS (SELECT 1 FROM Seat s2 WHERE s2.id = Seat.id - 1) THEN id - 1
        ELSE id
    END AS id,
    student
FROM Seat
ORDER BY id;
