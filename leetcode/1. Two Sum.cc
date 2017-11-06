// Copyright 2017 Qi Wang
// Date: 2017-11-06
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_to_idx_map;
    for (int i = 0; i < nums.size(); ++i) {
      if (num_to_idx_map.count(target - nums[i])) {
        return {num_to_idx_map[target - nums[i]], i};
      } else if (num_to_idx_map.count(nums[i]) == 0) {
        num_to_idx_map[nums[i]] = i;
      }
    }
    return {-1, -1};
  }
};

// Date: 2017-08-15
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_to_idx_map;
    for (int i = 0; i < nums.size(); ++i) {
      if (num_to_idx_map.find(target - nums[i]) !=
          num_to_idx_map.end()) {
        return {num_to_idx_map[target - nums[i]], i};
      } else {
        num_to_idx_map[nums[i]] = i;
      }
    }
    return {};  // comfort the compiler
  }
};

// Date: 2017-08-11
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_to_idx_map;
    for (int i = 0; i < nums.size(); ++i) {
      if (num_to_idx_map.find(target - nums[i]) !=
          num_to_idx_map.end()) {
        return {num_to_idx_map[target - nums[i]], i};
      } else {
        num_to_idx_map[nums[i]] = i;
      }
    }
    return {-1, -1};  // comfort the compiler
  }
};

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