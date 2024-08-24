# Write your MySQL query statement below
SELECT 'High Salary' as category ,(select count(*) from Accounts where income>50000) as accounts_count
UNION
SELECT 'Average Salary' as category ,(select count(*) from Accounts where income>=20000 AND income<=50000) as accounts_count
UNION
SELECT 'Low Salary' as category ,(select count(*) from Accounts where income<20000) as accounts_count