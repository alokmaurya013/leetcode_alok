# Write your MySQL query statement below
SELECT user AS id,COUNT('*') as num
FROM (
    SELECT requester_id as user FROM RequestAccepted
    UNION ALL
    SELECT accepter_id as user FROM RequestAccepted
) as all_user
GROUP BY user
ORDER BY num DESC
LIMIT 1