# Write your MySQL query statement below
WITH FirstLogin AS (
    SELECT
        player_id,
        MIN(event_date) AS first_login_date
    FROM Activity
    GROUP BY player_id
),
SecondLogin AS (
    SELECT
        a.player_id,
        MIN(a.event_date) AS second_login_date
    FROM Activity a
    JOIN FirstLogin fl
        ON a.player_id = fl.player_id
        AND a.event_date = DATE_ADD(fl.first_login_date, INTERVAL 1 DAY)
    GROUP BY a.player_id
),
TotalPlayers AS (
    SELECT COUNT(DISTINCT player_id) AS total
    FROM FirstLogin
),
ConsecutivePlayers AS (
    SELECT COUNT(DISTINCT fl.player_id) AS count_consecutive
    FROM FirstLogin fl
    JOIN SecondLogin sl
        ON fl.player_id = sl.player_id
)

SELECT
    ROUND(cp.count_consecutive / tp.total, 2) AS fraction
FROM TotalPlayers tp, ConsecutivePlayers cp;

