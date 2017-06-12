# Copyright 2017 Qi Wang
# Date: 2017-06-12
select (
  select distinct Salary
  from Employee
  order by Salary desc
  limit 1, 1
) as SecondHighestSalary
