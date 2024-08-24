# Write your MySQL query statement below
WITH day_sum_t as(
  SELECT visited_on,SUM(amount) as day_sum
  FROM Customer 
  GROUP BY visited_on
  ORDER BY visited_on
)

SELECT visited_on,
    SUM(day_sum) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS amount,
    ROUND(AVG(day_sum) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW),2) AS average_amount

FROM day_sum_t
LIMIT 18446744073709551615 OFFSET 6;