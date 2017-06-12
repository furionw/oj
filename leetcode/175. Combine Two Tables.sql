# Copyright 2017 Qi Wang
# Date: 2017-06-12
# Refer to:
#   - http://www.w3school.com.cn/sql/sql_join.asp
#   - https://dev.mysql.com/doc/refman/5.7/en/left-join-optimization.html
select FirstName, LastName, City, State
from Person
left join Address
on Person.PersonId = Address.PersonId;
