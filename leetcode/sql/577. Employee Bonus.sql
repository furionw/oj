# Copyright 2017 Qi Wang
# Date: 2017-06-14
select name, bonus
from Employee
left join Bonus
using (empId)
where bonus is null or bonus < 1000;
