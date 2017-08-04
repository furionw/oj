// Copyright 2017 Qi Wang
// Date: 2017-08-03
// Refer to: https://discuss.leetcode.com/topic/52302/1ms-java-dp-solution-with-detailed-explanation
class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; ++i) {
      for (int j = 0; j < nums.size(); ++j) {
        if (i - nums[j] >= 0) {
          dp[i] += dp[i - nums[j]];
        }
      }
    }
    return dp.back();
  }
};

// Date: 2017-07-30
// Divided by zero error when input is [[1, 50], 200]
class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> cnts;
    return F(nums, 0, &cnts, target);
  }

 private:
  int F(const vector<int>& nums, int idx, vector<int>* cnts, int target) const {
    if (target == 0) {
      return Permutation(*cnts);
    } else if (idx == nums.size() || nums[idx] > target) {
      return 0;
    } else {
      int result = F(nums, idx + 1, cnts, target);
      cnts->push_back(0);
      for (int cnt = 1; cnt * nums[idx] <= target; ++cnt) {
        cnts->back() = cnt;
        result += F(nums, idx + 1, cnts, target - cnt * nums[idx]);
      }
      cnts->pop_back();
      return result;
    }
  }

  int Permutation(const vector<int>& cnts) const {
    double result = Factorial(accumulate(cnts.begin(), cnts.end(), 0));
    for (int cnt : cnts) {
      result /= Factorial(cnt);
    }
    return result;
  }

  double Factorial(int num) const {
    double result = 1;
    for (int i = 2; i <= num; ++i) {
      result *= i;
    }
    return result;
  }
};

// Date: 2016-12-11
// Divided by zero error when input is [[1, 50], 200] -- 2017-07-30
class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> cnts;
    int res = 0;
    combinationSum4(nums, 0, target, cnts, res);
    return res;
  }

 private:
  void combinationSum4(const vector<int>& nums, size_t idx, int target,
      vector<int>& cnts, int& res) const {
    if (target == 0) {
      int solutionCnt = factor(accumulate(cnts.cbegin(), cnts.cend(), 0));
      for (int cnt : cnts) {
        solutionCnt /= factor(cnt);
      }
      res += solutionCnt;
      return;
    }
    if (idx == nums.size()) return;
    // take none
    combinationSum4(nums, idx + 1, target, cnts, res);
    // take some
    int cnt = target / nums[idx];
    cnts.push_back(0);
    for (int i = 0; i < cnt; ++i) {
      ++cnts.back();
      combinationSum4(nums, idx + 1, target -= nums[idx], cnts, res);
    }
    cnts.pop_back();
  }

  int factor(int n) const {
    int res = 1;
    for (int i = 2; i <= n; ++i) res *= i;
    return res;
  }
};
