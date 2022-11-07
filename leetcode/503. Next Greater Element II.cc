// 2022-11-06
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> res(nums.size(), -1);
    vector<bool> found(nums.size(), false);
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; --i) {
      for (; !s.empty() && nums[i] >= s.top(); s.pop()) {}
      if (!s.empty()) {
        res[i] = s.top();
        found[i] = true;
      }
      s.push(nums[i]);
    }
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (found[i]) {
        continue;
      }
      for (; !s.empty() && nums[i] >= s.top(); s.pop()) {}
      if (!s.empty()) {
        res[i] = s.top();
      }
    }
    return res;
  }
};


// Date: 2017-02-07
// Refer to my second impl in the 496. This implementation really boosts up
// Complexity: O(n) time
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> result(nums.size(), -1);
    // idx -> next greater element
    unordered_map<int, int> next;
    // pair : <val, idx>
    stack<pair<int, int>> stk;
    for (int i = 0; i < nums.size(); ++i) {
      for (; !stk.empty() && nums[i] > stk.top().first; stk.pop())
        next[stk.top().second] = nums[i];
      stk.push({nums[i], i});
    }
    for (int num : nums)
      for (; !stk.empty() && num > stk.top().first; stk.pop())
        next[stk.top().second] = num;
    for (const auto& p : next)
      result[p.first] = p.second;
    return result;
  }
};

// Date: 2017-02-07
// Complexity: O(n^2) time
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> result(nums.size());
    for (size_t i = 0; i < nums.size(); ++i) {
      size_t j = i + 1;
      for (; j < nums.size() && nums[j] <= nums[i]; ++j) {}
      if (j < nums.size()) {
        result[i] = nums[j];
        continue;
      }
      for (j = 0; j < i && nums[j] <= nums[i]; ++j) {}
      result[i] = j < i ? nums[j] : -1;
    }
    return result;
  }
};
