# Copyright 2017 Qi Wang
# Date: 2017-06-12
# Refer to: https://stackoverflow.com/questions/17250243/how-to-return-null-when-result-is-empty
select(
  select num
  from number
  group by num
  having count(*) = 1
  order by num desc limit 0, 1
) as num;
