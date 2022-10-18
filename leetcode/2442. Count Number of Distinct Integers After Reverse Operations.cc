// Date: 2022-10-17
class Solution {
 public:
  int countDistinctIntegers(vector<int>& nums) {
    unordered_set<int> s;
    for (int num : nums) {
      s.insert(num);
      int other = 0;
      for (; num > 0; num /= 10) {
        other = other * 10 + num % 10;
      }
      s.insert(other);
    }
    return s.size();
  }
};
