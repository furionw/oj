# Copyright 2017 Qi Wang
# Date: 2017-06-13
select Email
from Person
group by Email
having count(*) > 1;
