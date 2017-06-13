# Copyright 2017 Qi Wang
# Date: 2017-06-13
# Method 1
# Refer to: https://discuss.leetcode.com/topic/16097/simple-short-fast
SELECT
  Score,
  @rank := @rank + (@prev <> (@prev := Score)) Rank
FROM
  Scores,
  (SELECT @rank := 0, @prev := -1) init
ORDER BY Score DESC
