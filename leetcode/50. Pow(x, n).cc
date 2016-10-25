// Copyright 2016 Qi Wang
// Date: 2016-10-25
class Solution {
 public:
  double myPow(double x, int n) {
    if (n < 0) {
      // handle the case where n == INT_MIN and -n cannot be represented by int
      return n != INT_MIN
          ? 1 / myPow(x, -n)
          : 1 / myPow(x, INT_MAX) / x;
    } else if (n == 0) {
      return 1;
    } else {
      double sqrt = myPow(x, n / 2);
      return sqrt * sqrt * (n % 2 == 0 ? 1 : x);
    }
  }
};

// Date: 2014-07
class Solution 
{
public:
    double pow(double x, int n) 
    {
      if (n == 0)
      {
        return 1;
      }

      bool negative = n<0;
    double ret=x;
      long long tmp = 1, cnt = 0;
    long long nn = n;
      while (tmp*2 <= abs(nn))
      {
        tmp *= 2;
        ++ cnt;
      }
      while (cnt --)
      {
        ret *= ret;
      }

      return negative? 1/(ret*pow(x, abs(n)-tmp)): ret*pow(x, abs(n)-tmp);
    }
};