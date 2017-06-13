# Copyright 2017 Qi Wang
# Date: 2017-06-13
# Method 2: faster than method 1
# Syntax reference:
#   - https://stackoverflow.com/questions/45494/mysql-error-1093-cant-specify-target-table-for-update-in-from-clause
#   - https://stackoverflow.com/questions/14767209/subquery-in-from-must-have-an-alias
DELETE FROM Person
WHERE Id NOT IN (
  SELECT P.Id
  FROM (
    SELECT MIN(Id) AS Id
    FROM Person
    GROUP BY Email
  ) AS P
);

# Date: 2017-06-13
# Refer to: https://stackoverflow.com/questions/4685173/delete-all-duplicate-rows-except-for-one-in-mysql
# Method 1
DELETE p1
FROM Person p1, Person p2
WHERE p1.id > p2.id AND p1.Email = p2.Email;
