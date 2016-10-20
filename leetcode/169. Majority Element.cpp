// Copyright 2016 Qi Wang
// Date: 2016-10-05
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int candidate, cnt = 0;
    for (int num : nums) {
      if (cnt == 0) {
        candidate = num;
        ++cnt;
      } else {
        cnt += (candidate == num ? 1 : -1);
      }
    }
    return candidate;
  }
};

// Date: 2015-05
class Solution 
{
public:
    int majorityElement(vector<int> &num) 
    {
        int candidate;
        int cnt = 0;

        for (size_t i = 0; i < num.size(); ++ i)
        {
        	if (cnt == 0)
        	{
        		candidate = num[i];
        		++ cnt;
        	} else
        	{
        		cnt += (candidate==num[i])? 1: -1;
        	}
        }

        return candidate;
    }
};