# Copyright 2017 Qi Wang
# Date: 2017-06-13
select Name as Customers
from Customers
where Id not in (
  select CustomerId
  from Orders
)
