# Copyright 2017 Qi Wang
# Date: 2017-08-07
# Refer to:
#   - https://discuss.leetcode.com/topic/96051/1-liner-with-explanation
SELECT IFNULL(
  ROUND(
    (SELECT COUNT(DISTINCT requester_id, accepter_id)
    FROM request_accepted) /
    (SELECT COUNT(DISTINCT sender_id, send_to_id)
    FROM friend_request), 2),
  0) AS accept_rate
