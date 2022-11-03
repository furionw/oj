// Date: 2022-11-02
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    for (int num1 : nums1) {
      bool foundEq = false;
      bool foundGr = false;
      for (int num2 : nums2) {
        if (num1 == num2) {
          foundEq = true;
          continue;
        }
        if (foundEq && num2 > num1) {
          result.push_back(num2);
          foundGr = true;
          break;
        }
      }
      if (!foundGr) {
        result.push_back(-1);
      }
    }
    return result;
  }
};

// Date: 2017-02-07
// Refer to: https://discuss.leetcode.com/topic/77916/java-10-lines-linear-time-complexity-o-n-with-explanation
// Complexity: O(n) time
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    unordered_map<int, int> next;
    vector<int> result(findNums.size());
    stack<int> stk;
    for (int num : nums) {
      for (; !stk.empty() && num > stk.top(); stk.pop()) {
        next[stk.top()] = num;
      }
      stk.push(num);
    }
    for (size_t i = 0; i < findNums.size(); ++i) {
      result[i] = next.count(findNums[i]) == 1
          ? next[findNums[i]]
          : -1;
    }
    return result;
  }
};

// Date: 2017-02-07
// Complexity: O(mn) time
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    if (nums.empty()) return vector<int>();
    vector<int> result(findNums.size());
    for (size_t i = 0; i < findNums.size(); ++i) {
      auto it = find(nums.begin(), nums.end(), findNums[i]);
      for (++it; it != nums.end() && *it < findNums[i]; ++it) {}
      result[i] = it == nums.end() ? -1 : *it;
    }
    return result;
  }
};
