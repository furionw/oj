// Copyright 2016 Qi Wang
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