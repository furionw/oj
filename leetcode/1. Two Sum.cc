// Copyright 2017 Qi Wang
// Date: 2017-07-25
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> record;
    for (int i = 0; i < nums.size(); ++i) {
      auto itr = record.find(target - nums[i]);
      if (itr != record.end()) {
        return {itr->second, i};
      } else {
        record[nums[i]] = i;
      }
    }
    return {-1, -1};  // comfort the compiler
  }
};


class Solution 
{
public:
    vector<int> twoSum(vector<int> &numbers, int target) 
    {
      vector<int> ret, tmp=numbers;
      int first, second;

      sort(tmp.begin(), tmp.end());
      for (size_t i = 0; i < numbers.size(); ++ i)
      {
        if (find(tmp, target-numbers[i]))
        {
          first = i;
                bool find_second = false;
                for (size_t j = first+1; j < numbers.size(); ++ j)
                {
                    if (numbers[j] == target-numbers[first])
                    {
                        second = j;
                        find_second = true;
                        break;
                    }
                }
                if (find_second == true)
                {
                    break;
                }
        }
      }
      for (size_t i = first+1; i < numbers.size(); ++ i)
      {
        if (numbers[i] == target-numbers[first])
        {
          second = i;
          break;
        }
      }

      ret.push_back(first+1);
      ret.push_back(second+1);
      return ret; // soft the compiler
    }

    bool find(vector<int> &numbers, int target)
    {
      int left = 0, right=numbers.size()-1;
      while (left <= right)
      {
        int mid = (left+right)/2;
        if (numbers[mid] == target)
        {
          return true;
        } else if (numbers[mid] < target)
        {
          left = mid+1;
        } else
        {
          right = mid-1;
        }
      }
      return false;
    }
};