# Write your MySQL query statement below
(SELECT name as results
 FROM MovieRating
LEFT JOIN Users Using(user_id)
 GROUP BY name
 ORDER BY COUNT(*) desc,name LIMIT 1
)
UNION ALL
(SELECT title as results 
 FROM MovieRating
LEFT JOIN Movies USING(movie_id)
WHERE MovieRating.created_at LIKE '2020-02%'
GROUP BY title
ORDER BY avg(rating) desc,title LIMIT 1
)