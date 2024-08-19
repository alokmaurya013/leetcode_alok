# Write your MySQL query statement below
# SELECT * 
# FROM Signups;

SELECT Signups.user_id,ROUND(AVG(If(Confirmations.action='confirmed',1,0)),2) as confirmation_rate
FROM Signups
LEFT JOIN Confirmations
ON Signups.user_id=Confirmations.user_id
GROUP BY Signups.user_id