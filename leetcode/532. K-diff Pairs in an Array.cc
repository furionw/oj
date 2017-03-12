// Copyright 2017 Qi Wang
// Date: 2017-03-12
// Method 3: Use "map" when k == 0, "set" when k > 0

// Method 2
class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0;
    unordered_map<int, int> m;
    for (int num : nums) ++m[num];
    return count_if(m.begin(), m.end(), k == 0
        ? (function<bool(const pair<int, int>& p)>)
              ([](const pair<int, int>& p) { return p.second > 1; })
        : [&m, k](const pair<int, int>& p) { return m.count(p.first + k) >= 1; });
  }
};

// Date: 2017-03-12
// Method 1
class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    if (k < 0 || nums.empty()) return 0;
    sort(nums.begin(), nums.end());
    int result = 0;
    auto slow = nums.begin(),
         fast = lower_bound(++nums.begin(), nums.end(), *slow + k);
    if (fast != nums.end() && *fast == *slow + k) result = 1;
    int prev = *slow;
    while (true) {
      for (; slow != nums.end() && *slow == prev; ++slow) {}
      fast = slow;
      if (slow == nums.end() || ++fast == nums.end()) break;
      fast = lower_bound(fast, nums.end(), *slow + k);
      if (fast != nums.end() && *fast == *slow + k) ++result;
      prev = *slow;
    }
    return result;
  }
};
