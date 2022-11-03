// Refer to: https://leetcode.com/problems/next-greater-element-iv/discuss/2756668/JavaC%2B%2BPython-One-Pass-Stack-Solution-O(n)
// Also see a list of similar problems. Should be tackled together
class Solution {
 public:
  vector<int> secondGreaterElement(vector<int>& nums) {
    stack<int> s1, s2, tmp;
    vector<int> res(nums.size(), -1);
    for (int i = 0; i < nums.size(); ++i) {
      for (; !s2.empty() && nums[i] > nums[s2.top()]; s2.pop()) {
        res[s2.top()] = nums[i];
      }
      // Injecting numbers into `s2` in decreasing order
      for (; !s1.empty() && nums[i] > nums[s1.top()]; s1.pop()) {
        tmp.push(s1.top());
      }
      for (; !tmp.empty(); tmp.pop()) {
        s2.push(tmp.top());
      }
      s1.push(i);
    }
    return res;
  }
};
