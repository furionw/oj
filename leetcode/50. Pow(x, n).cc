// Copyright 2017 Qi Wang
// Date: 2017-11-10
class Solution {
 public:
  double myPow(double x, int n) {
    if (n == 0) {
      return 1;
    } else if (n == INT_MIN) {
      return 1 / (x * myPow(x, INT_MAX));
    } else if (n < 0) {
      if (x == 0) return INT_MIN;
      return 1 / myPow(x, -n);
    } else {
      double val = myPow(x, n >> 1);
      return val * val * (n % 2 == 1 ? x : 1);
    }
  }
};

// Date: 2017-08-14
class Solution {
 public:
  double myPow(double x, int n) {
    if (n == 0) return 1;
    int64_t nn = n;
    bool negative = nn < 0;
    nn = abs(nn);
    double i = myPow(x, nn >> 1);
    double result = i * i * (n & 1 ? x : 1);
    return negative ? 1 / result : result;
  }
};

// Date: 2017-07-31
class Solution {
 public:
  double myPow(double x, int n) {
    if (n == INT_MIN) {
      return 1 / myPow(x, INT_MAX) / x;
    } if (n < 0) {
      return 1 / myPow(x, -n);
    } else if (n == 0) {
      return 1;
    } else if (n == 1) {
      return x;
    } else {
      double elem = myPow(x, n / 2);
      return elem * elem * (n % 2 == 1 ? x : 1);
    }
  }
};

// Date: 2017-01-03
// Note that I think the solution on 2016-10-25 is better (more concise)
class Solution {
 public:
  double myPow(double x, int n) {
    // negative n
    if (n == INT_MIN) {
      double sqrt = myPow(x, n >> 1);
      return sqrt * sqrt;
    } else if (n < 0) {
      return 1 / myPow(x, -n);
    // non negative n
    } else if (!n) {
      return 1;
    } else if (n == 1) {
      return x;
    } else {
      double sqrt = myPow(x, n >> 1);
      return sqrt * sqrt * ((n & 1) ? x : 1);
    }
  }
};

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