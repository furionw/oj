# Copyright 2017 Qi Wang
# Date: 2017-06-14
# Method 2: takes almost the same time as method 1
select cur.id
from Weather as prev
inner join Weather as cur
on DATEDIFF(cur.Date, prev.Date) = 1 and prev.Temperature < cur.Temperature

# Date: 2017-06-14
# Method 1
select cur.Id
from Weather as prev, Weather as cur
where DATEDIFF(cur.Date, prev.Date) = 1 and prev.Temperature < cur.Temperature
