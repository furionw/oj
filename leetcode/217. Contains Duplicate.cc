// Copyright 2017 Qi Wang
// Date: 2017-02-09
class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (int num : nums) {
      if (s.count(num))
        return true;
      s.insert(num);
    }
    return false;
  }
};

// Date: 2015-06
class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        set<int> s;
        for (auto it = nums.begin(); it != nums.end(); ++ it)
        {
            s.insert(*it);
        }
        return s.size() != nums.size();
    }
};
