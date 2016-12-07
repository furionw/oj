// Copyright 2016 Qi Wang
// Method 3
class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    if (nums.size() <= 1) return nums;
    sort(nums.begin(), nums.end());
    int cnt[nums.size()], pre[nums.size()];
    fill(cnt, cnt + nums.size(), 1);
    int maxIdx = 0;
    for (size_t i = 1; i < nums.size(); ++i) {
      for (size_t j = 0; j < i; ++j) {
        if (nums[i] % nums[j] == 0 && cnt[j] + 1 > cnt[i]) {
          cnt[i] = cnt[j] + 1;
          pre[i] = static_cast<int>(j);
        }
      }
      if (cnt[i] > cnt[maxIdx]) maxIdx = i;
    }
    vector<int> res(1, nums[maxIdx]);
    for (int i = maxIdx; cnt[i] > 1; i = pre[i])
      res.push_back(nums[pre[i]]);
    return res;
  }
};

// Method 2
// TLE
// Date: 2016-12-07
class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return r(nums, 0);
  }

 private:
  vector<int> r(const vector<int>& nums, size_t begin) {
    if (begin == nums.size()) return vector<int>();
    vector<vector<int>> numTbl;
    for (size_t i = begin; i < nums.size(); ++i) {
      int num = nums[i];
      bool find = false;
      for (auto& subset : numTbl) {
        if (num % subset.front() == 0) {
          subset.push_back(num);
          find = true;
          break;
        }
      }
      if (!find)
        numTbl.push_back(vector<int>(1, num));
    }
    int resIdx = 0;
    vector<int> res;
    for (size_t i = 0; i < numTbl.size(); ++i) {
      for (size_t j = 1; j < numTbl[i].size(); ++j) {
        auto temp = r(numTbl[i], j);
        if (temp.size() > res.size()) {
          res = temp;
          resIdx = static_cast<int>(i);
        }
      }
    }
    res.insert(res.begin(), numTbl[resIdx].front());
    return res;
  }
};

// Method 1
// TLE
// Date: 2016-12-07
class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int> cur, res;
    r(nums, 0, cur, res);
    return res;
  }

 private:
  void r(const vector<int>& nums, size_t i, vector<int>& cur, vector<int>& res) {
    if (cur.size() > res.size()) res = cur;
    if (i == nums.size()) return;
    bool valid = true;
    for (size_t j = 0; j < cur.size() && valid; ++j)
      // "nums" contains only positive integers
      valid = valid && (nums[i] % cur[j] == 0 || cur[j] % nums[i] == 0);
    if (valid) {
      cur.push_back(nums[i]);
      r(nums, i + 1, cur, res);
      cur.pop_back();
    }
    r(nums, ++i, cur, res);
  }
};
