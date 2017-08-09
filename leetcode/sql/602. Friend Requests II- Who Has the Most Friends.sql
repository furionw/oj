# Copyrigth 2017 Qi Wang
# Date: 2017-08-08
# Refer to: https://discuss.leetcode.com/topic/95376/shouldn-t-we-use-union-instead-of-union-all
# Note that this impl hasn't been AC Yet because I think the LC judge's solution
# is wrong
SELECT id, count(*) AS num
FROM (
  SELECT requester_id AS id, accepter_id AS id2
  FROM request_accepted
  UNION
  SELECT accepter_id AS id, requester_id AS id2
  FROM request_accepted
) AS temp
GROUP BY id
ORDER BY num DESC
LIMIT 1
