// Copyright 2016 Qi Wang
// Date: 2016-12-25
// Method 2: refer to the Top Solutions
class Solution {
 public:
  vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    if (nums.empty()) return vector<int>();
    for (int& num : nums) num = a * num * num + b * num + c;
    vector<int> res(nums.size());
    if (a >= 0) {
      for (int i = 0, j = static_cast<int>(nums.size()) - 1,
          idx = static_cast<int>(nums.size()) - 1; i <= j; --idx)
        res[idx] = nums[i] > nums[j] ? nums[i++] : nums[j--];
    } else {
      for (int i = 0, j = static_cast<int>(nums.size()) - 1, idx = 0;
          i <= j; ++idx)
        res[idx] = nums[i] < nums[j] ? nums[i++] : nums[j--];
    }
    return res;
  }
};

// Date: 2016-12-25
// Method 1
class Solution {
 public:
  vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    if (nums.empty()) return vector<int>();
    if (a == 0) {
      if (b == 0) return vector<int>(nums.size(), c);
      for (int& num : nums) num = b * num + c;
      if (b < 0) reverse(nums.begin(), nums.end());
      return nums;
    }
    double center = -b / (2. * a);
    int mid;
    for (int l = 0, r = static_cast<int>(nums.size()) - 1; l <= r;) {
      mid = l + r >> 1;
      if (nums[mid] == center) {
        break;
      } else if (nums[mid] < center) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    int i, j;
    if (mid == 0) {
      i = 0, j = 1;
    } else if (mid == nums.size() - 1) {
      i = mid - 1, j = mid;
    } else if (nums[mid] < center) {
      i = mid, j = mid + 1;
    } else {
      i = mid - 1, j = mid;
    }
    vector<int> res;
    while (i >= 0 && j < nums.size()) {
      if (fabs(nums[i] - center) < fabs(nums[j] - center)) {
        res.push_back(a * nums[i] * nums[i] + b * nums[i] + c);
        --i;
      } else {
        res.push_back(a * nums[j] * nums[j] + b * nums[j] + c);
        ++j;
      }
    }
    for (; i >= 0; --i)
      res.push_back(a * nums[i] * nums[i] + b * nums[i] + c);
    for (; j < nums.size(); ++j)
      res.push_back(a * nums[j] * nums[j] + b * nums[j] + c);
    if (a < 0) reverse(res.begin(), res.end());
    return res;
  }
};
