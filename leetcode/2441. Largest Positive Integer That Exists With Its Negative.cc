// Date: 2022-10-17
class Solution {
 public:
  int findMaxK(vector<int>& nums) {
    set<int> s;
    for (int num : nums) {
      s.insert(num);
    }
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
      if (*it <= 0) {
        return -1;
      }
      if (s.count(-*it)) {
        return *it;
      }
    }
    return -1;
  }
};
