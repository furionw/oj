// Copyright 2017 Qi Wang
// Date: 2017-08-01
class Solution {
 public:
  int mySqrt(int x) {
    if (x < 0) return -1;
    int l = 0, r = x;
    while (l < x) {
      uint64_t mid = (l + r) >> 1;
      uint64_t num1 = mid * mid;
      uint64_t num2 = (mid + 1) * (mid + 1);
      if (num1 <= x) {
        if (num2 > x) {
          return mid;
        } else {
          l = mid + 1;
        }
      } else {
        r = mid - 1;
      }
    }
    return l;
  }
};

class Solution 
{
public:
    int sqrt(int x) 
  {
        long long l=1, r=x, mid=x;

        while (l <= r)
        {
          mid = (l+r) >> 1;
          if (mid*mid == x)
          {
            return mid;
          } else if (mid*mid < x)
          {
            l = mid + 1;
          } else
          {
            r = mid - 1;
          }
        }

        return mid*mid>x? mid-1:mid;
    }
};