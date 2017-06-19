# Copyright 2017 Qi Wang
# Date: 2017-06-19
select *
from cinema
where id % 2 <> 0 and description <> 'boring'
order by rating desc;
