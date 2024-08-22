# Write your MySQL query statement below
SELECT w1.id
FROM Weather as w1
INNER JOIN Weather as w2 
on DATEDIFF(w1.recordDate,w2.recordDate)=1
WHERE w1.temperature>w2.temperature
