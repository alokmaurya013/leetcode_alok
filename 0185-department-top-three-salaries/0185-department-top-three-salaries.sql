# Write your MySQL query statement below
SELECT Department,Employee,Salary
FROM
(SELECT d.name as Department,e.name as Employee ,e.salary as Salary,
   DENSE_RANK() OVER (PARTITION BY d.id ORDER BY e.salary DESC) as rk
FROM Employee e
LEFT JOIN Department d ON e.departmentId=d.id
 ) as tmp
 WHERE rk<=3
