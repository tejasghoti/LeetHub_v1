DELETE FROM Person
WHERE id NOT IN (
  SELECT min_id FROM (
    SELECT MIN(id) as min_id
    FROM Person
    GROUP BY email
  ) as a
);
