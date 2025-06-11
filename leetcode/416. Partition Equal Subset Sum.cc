// 2025-06-10
// Refer to the Editorial -- 1D dp array
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    // calculate sumsetSum
    int subsetSum = 0;
    for (int num : nums) {
      subsetSum += num;
    }
    if (subsetSum % 2 != 0) {
      return false;
    }
    subsetSum /= 2;

    int n = nums.size();
    vector<bool> dp(subsetSum + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
      for (int j = subsetSum; j >= 1; --j) {
        int prevJ = j - nums[i - 1];
        if (prevJ < 0) {
          continue;
        }
        dp[j] = dp[j] || dp[prevJ];
        if (dp[subsetSum]) {
          return true;
        }
      }
    }
    return false;
  }
};

// 2025-06-10
// Refer to the Editorial
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    // calculate sumsetSum
    int subsetSum = 0;
    for (int num : nums) {
      subsetSum += num;
    }
    if (subsetSum % 2 != 0) {
      return false;
    }
    subsetSum /= 2;

    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(subsetSum + 1, false));
    for (int i = 0; i <= n; ++i) {
      dp[i][0] = true;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= subsetSum; ++j) {
        dp[i][j] = dp[i - 1][j];
        int prevJ = j - nums[i - 1];
        if (prevJ < 0) {
          continue;
        }
        dp[i][j] = dp[i][j] || dp[i - 1][prevJ];
        if (j == subsetSum && dp[i][j]) {
          return true;
        }
      }
    }
    return false;
  }
};

// 2025-06-10
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    unordered_set<int> partials;
    for (int num : nums) {
      sum += num;
    }
    if (sum % 2 != 0) {
      return false;
    }
    int target = sum / 2;
    for (int num : nums) {
      unordered_set<int> next;
      if (num == target) {
        return true;
      }
      next.insert(num);
      for (int partial: partials) {
        if (num + partial == target) {
          return true;
        }
        next.insert(num + partial);
        next.insert(partial);
      }
      partials = std::move(next);
    }
    return false;
  }
};

// Method 2
// Dynamic programming
// Refer to: https://discuss.leetcode.com/topic/62271/c-solution-with-dynamic-programming/4
// Date: 2016-11-15
// Revisit: 2017-10-18
// dp[i][j]: The sum of none or some of the elements in nums[0, ..., j - 1] is i.
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) return false;
    int target = sum >> 1;
    // dp[i][j] is true iff the sum of the subset of the first j numbers is i
    bool dp[1 + target][nums.size() + 1];
    for (int i = 0; i <= target; ++i)
      for (int j = 0; j <= nums.size(); ++j)
        dp[i][j] = !i;
    for (int i = 1; i <= target; ++i)
      for (int j = 1; j <= nums.size(); ++j)
        if (nums[j - 1] <= i)
          dp[i][j] = dp[i][j - 1] || dp[i - nums[j - 1]][j - 1];
    return dp[target][nums.size()];
  }
};

// Method 1
// TLE: nums.size() <= 200, 2^200 is too large!!!
// Date: 2016-11-14
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    return canPartition(nums, 0, 0, 0);
  }
 
 private:
  bool canPartition(vector<int>& nums, size_t cur, int sum1, int sum2) {
    return cur == nums.size()
        ? sum1 == sum2
        : canPartition(nums, cur + 1, sum1 + nums[cur], sum2)
            || canPartition(nums, cur + 1, sum1, sum2 + nums[cur]);
  }
};
