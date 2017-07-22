// Copyright 2017 Qi Wang
// Date: 2017-07-21
// Please note that the solution on 2016-11-04 is more concise.
class Solution {
 public:
  string convertToTitle(int n) {
    string result;
    for (; n > 0; n /= 26) {
      int r = n % 26;
      if (r == 0) {
        result += 'Z';
        n -= 26;
      } else {
        result += r + 'A' - 1;
      }
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

// Date: 2016-11-04
class Solution {
 public:
  string convertToTitle(int n) {
    string res;
    for (; n; n = (n - 1) / 26)
      res += 'A' + (n - 1) % 26;
    reverse(res.begin(), res.end());
    return res;
  }
};

// Date: 2015-03
class Solution 
{
public:
    string convertToTitle(int n) 
    {
    	string ret;
    	while (n != 0)
    	{
    		ret.insert(ret.begin(), 'A' + (n-1)%26);
    		n = (n-1) / 26;
    	}    
    	return ret;
    }
};