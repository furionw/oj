// Copyright 2017 Qi Wang
// Date: 2017-08-16
class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int result = INT_MAX;
    for (int begin = 0, i = 0, acc = 0; i < nums.size(); ++i) {
      acc += nums[i];
      for (; acc - nums[begin] >= s; acc -= nums[begin++]) {}
      if (acc >= s) result = min(result, i - begin + 1);
    }
    return result != INT_MAX ? result : 0;
  }
};

// Date: 2017-07-25
class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    if (nums.empty()) return 0;
    int acc = nums.front(), prev = 0;
    if (acc > s) return 1;
    int result = INT_MAX;
    for (int i = 1; i < nums.size(); ++i) {
      acc += nums[i];
      while (prev != i && acc - nums[prev] >= s) {
        acc -= nums[prev];
        ++prev;
      }
      if (acc >= s) {
        result = min(result, i - prev + 1);
      }
    }
    return result != INT_MAX ? result : 0;
  }
};

// Date: 2017-03-09
// O(nlogn) solution required by follow up question
class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int acc = 0;
    for (int& num : nums) num = (acc += num);
    int result = INT_MAX;
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] >= s)
        result = min(result,
            i - binary_search(nums, i - 1, nums[i] - s));
    return result != INT_MAX ? result : 0;
  }

 private:
  int binary_search(const vector<int>& nums, int r, int target) const {
    for (int l = 0; l <= r; ) {
      int mid = (l + r) >> 1;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return r;
  }
};

// Date: 2017-02-10
// O(n) time solution
// 12ms
class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    size_t result = INT_MAX, sum = 0;
    for (size_t begin = 0, i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      while (begin < i && sum - nums[begin] >= s)
        sum -= nums[begin++];
      if (sum >= s)
        result = min(result, i - begin + 1);
    }
    return result == INT_MAX ? 0 : result;
  }
};

// Date: 2017-02-10
// 159ms
class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    for (int result = 1; result <= nums.size(); ++result) {
      int sum = accumulate(nums.begin(), nums.begin() + result, 0);
      if (sum >= s) return result;
      for (int i = result; i < nums.size(); ++i)
        if ((sum += nums[i] - nums[i - result]) >= s)
          return result;
    }
    return 0;
  }
};

class Solution 
{
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
      if (nums.empty())
      {
        return 0;
      }

      vector<int> sum(nums.size(), 0);
      vector<int> len(nums.size(), 0);
      sum[0] = nums[0];
      len[0] = 1;
      int min_len = sum[0]>=s? 1: INT_MAX;
      int begin = 0;

      for (size_t i = 1; i < nums.size(); ++ i)
      {
       sum[i] = sum[i-1] + nums[i];
        if (sum[i] < s)
        {
          len[i] = len[i-1] + 1;
        } else
        {
          // note that this 'begin' won't be larger than nums.size()
          for (; sum[i] - nums[begin] >= s; sum[i] -= nums[begin], ++ begin) {}
          len[i] = i - begin + 1;
          min_len = min(min_len, len[i]);
        }
      }

      return min_len==INT_MAX? 0: min_len;
    }
};
