// Copyright 2017 Qi Wang
// Date: 2017-11-09
class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> num_set;
    for (int num : nums) {
      num_set.insert(num);
    }
    int result = 0;
    while (!num_set.empty()) {
      int cnt = 1, num = *num_set.begin();
      num_set.erase(num);
      for (int offset = 1; num_set.count(num + offset); ++offset) {
        ++cnt;
        num_set.erase(num + offset);
      }
      for (int offset = 1; num_set.count(num - offset); ++offset) {
        ++cnt;
        num_set.erase(num - offset);
      }
      result = max(result, cnt);
    }
    return result;
  }
};

// Date: 2017-07-27
class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> num_set;
    for (int num : nums) {
      num_set.insert(num);
    }
    int result = 0;
    while (!num_set.empty()) {
      int num = *num_set.begin(); num_set.erase(num);
      int cnt = 1;
      for (int i = num + 1; num_set.find(i) != num_set.end(); ++i) {
        ++cnt;
        num_set.erase(i);
      }
      for (int i = num - 1; num_set.find(i) != num_set.end(); --i) {
        ++cnt;
        num_set.erase(i);
      }
      result = max(result, cnt);
    }
    return result;
  }
};

// Date: 2017-01-12
class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s;
    for (int num : nums)
      s.insert(num);
    int result = 0;
    while (!s.empty()) {
      int num = *s.begin(), len = 1;
      s.erase(num);
      for (int cur = num - 1; s.count(cur); --cur, ++len)
        s.erase(cur);
      for (int cur = num + 1; s.count(cur); ++cur, ++len)
        s.erase(cur);
      result = max(result, len);
    }
    return result;
  }
};

//
class Solution 
{
public:
    int longestConsecutive(vector<int> &num) 
    {
        if (num.size() == 0)
        {
            return 0;
        }

        int ret = 1, tmp = 1;
        sort(num.begin(), num.end());
        for (size_t i = 1; i < num.size(); ++ i)
        {
            if (num[i] == num[i-1] + 1)
            {
                ++ tmp;
                ret = max(ret, tmp);
            } else if (num[i] != num[i-1])
            {
                tmp = 1;
            }
        }
        return ret;
    }
};

// 
class Solution 
{
public:
    int longestConsecutive(vector<int> &num) 
    {
      if (num.size() == 0)
      {
        return 0;
      }

      int ret = 1;
      int cnt = 1;
      int prev = -1;
      priority_queue<int> q;

      for (size_t i = 0; i < num.size(); ++ i)
      {
        q.push( num[i] );
      }
      while (q.empty() == false)
      {
        int top = q.top();
        if (top + 1 == prev)
        {
          ++ cnt;
        } else if (top == prev)
        {
          // do nothing
        } else
        {
          cnt = 1;
        }
        prev = top;        
        ret = max(ret, cnt);
        q.pop();
      }

      return ret;
    }
};