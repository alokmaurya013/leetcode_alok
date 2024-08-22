# Write your MySQL query statement below
SELECT class
FROM Courses
GROUP BY Courses.class
HAVING COUNT(student)>=5