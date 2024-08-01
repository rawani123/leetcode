# Write your MySQL query statement below
WITH first_orders AS (
    SELECT
        customer_id,
        MIN(order_date) AS first_order_date
    FROM
        Delivery
    GROUP BY
        customer_id
),
immediate_first_orders AS (
    SELECT
        d.customer_id,
        d.order_date,
        d.customer_pref_delivery_date
    FROM
        Delivery d
    JOIN
        first_orders fo
    ON
        d.customer_id = fo.customer_id
        AND d.order_date = fo.first_order_date
    WHERE
        d.order_date = d.customer_pref_delivery_date
)
SELECT
    ROUND(COUNT(ifo.customer_id) * 100.0 / COUNT(fo.customer_id), 2) AS immediate_percentage
FROM
    first_orders fo
LEFT JOIN
    immediate_first_orders ifo
ON
    fo.customer_id = ifo.customer_id;

