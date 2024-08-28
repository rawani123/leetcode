WITH user_counts AS (
  SELECT u.name, COUNT(*) AS rating_count
  FROM Users u
  JOIN MovieRating r ON u.user_id = r.user_id
  GROUP BY u.user_id, u.name
  ORDER BY rating_count DESC, u.name ASC
  LIMIT 1
),
movie_avg_ratings AS (
  SELECT m.title, AVG(r.rating) AS avg_rating
  FROM Movies m
  JOIN MovieRating r ON m.movie_id = r.movie_id
  WHERE DATE_FORMAT(r.created_at, '%Y-%m') = '2020-02'
  GROUP BY m.movie_id, m.title
  ORDER BY avg_rating DESC, m.title ASC
  LIMIT 1
)

SELECT name AS results FROM user_counts
UNION ALL
SELECT title AS results FROM movie_avg_ratings;
