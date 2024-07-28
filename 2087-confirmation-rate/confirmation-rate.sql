# Write your MySQL query statement below
WITH ConfirmationsSummary AS (
    SELECT 
        user_id, 
        COUNT(*) AS total_requests, 
        SUM(CASE WHEN action = 'confirmed' THEN 1 ELSE 0 END) AS confirmed_requests
    FROM 
        Confirmations
    GROUP BY 
        user_id
),
UsersWithConfirmationRates AS (
    SELECT
        s.user_id,
        COALESCE(
            ROUND(
                (cs.confirmed_requests * 1.0 / cs.total_requests), 
                2
            ), 
            0
        ) AS confirmation_rate
    FROM 
        Signups s
    LEFT JOIN 
        ConfirmationsSummary cs 
    ON 
        s.user_id = cs.user_id
)
SELECT 
    user_id, 
    confirmation_rate
FROM 
    UsersWithConfirmationRates;

