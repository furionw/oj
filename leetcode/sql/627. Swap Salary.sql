# Copyright 2017 Qi Wang
# Date: 2017-06-19
# Refer to:
#   - https://stackoverflow.com/questions/8763310/how-do-write-if-else-statement-in-a-mysql-query
#   - https://discuss.leetcode.com/topic/93081/short-and-simple
select id, name, salary, 
  (case when sex = 'f' then 'm' else 'f' end) as sex
from salary;
