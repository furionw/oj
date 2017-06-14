# Copyright 2017 Qi Wang
# Date: 2017-06-14
select Name as name
from customer
where referee_id is null or referee_id <> 2;
