// Copyright 2016 Qi Wang
// Date: 2016-12-19
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    int mask = 1;
    for (int i = x; i /= 10; mask *= 10) {}
    for (; mask >= 10; mask /= 100) {
      if (x / mask != x % 10) return false;
      x = (x % mask) / 10;
    }
    return true;
  }
};

// Date: 2016-03
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;

    int base = 1;
    for (int num = x; num / 10 > 0; num /= 10)
      base *= 10;

    while (x != 0)
      if (x / base != x % 10) {
        return false;
      } else {
        x = (x % base) / 10;
        base /= 100;
      }

    return true;
  }
};

// Date: 2014-06
class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if (x < 0)
        {
        	return false;
        }

        int rightmost = 1;
        for (int copy = x/10; copy>0; copy/=10, rightmost*=10) {}
        while (x != 0)
        {
        	if (x/rightmost != x%10)
        	{
        		return false;
        	} else
        	{
        		x = (x%rightmost)/10; // cut off the rightmost and leftmost digits
           		rightmost /= 100;
        	}
        }    		

        return true;
    }
};