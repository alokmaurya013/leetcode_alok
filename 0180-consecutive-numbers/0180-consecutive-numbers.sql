# Write your MySQL query statement below
SELECT DISTINCT num as ConsecutiveNums
FROM (
    SELECT
    LAG(num) OVER (ORDER BY id) as num1,
    num,
    LEAD(num) OVER (ORDER BY id) as num2,
    LAG(id) OVER (ORDER BY id) as id1,
    id,
    LEAD(id) OVER (ORDER BY id) as id2
    FROM Logs
) as tmp
WHERE num=num1 AND num=num2 AND id=id1+1 AND id=id2-1
