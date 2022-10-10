// Date: 2022-10-08
class Solution {
 public:
  int longestContinuousSubstring(string s) {
    int result = 1;
    int cur = 1;
    char prev = s[0];
    for (size_t i = 1; i < s.size(); ++i) {
      if (s[i] == prev + 1) {
        ++cur;
      } else {
        result = max(result, cur);
        cur = 1;
      }
      prev = s[i];
    }
    result = max(result, cur);
    return result;
  }
};
