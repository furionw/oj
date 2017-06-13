# Copyright 2017 Qi Wang
# Date: 2017-06-13
select e.Name as Employee
from Employee as e
where e.ManagerId is not null and e.Salary > (
  select Salary
  from Employee
  where Id = e.ManagerId
)
