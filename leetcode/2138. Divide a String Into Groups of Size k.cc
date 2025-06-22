// 2025-06-21
class Solution {
 public:
  vector<string> divideString(string s, int k, char fill) {
    vector<string> result;
    for (int i = 0; i < s.size(); i += k) {
      result.push_back(s.substr(i, k));
    }
    while (result.back().size() < k) {
      result.back().push_back(fill);
    }
    return result;
  }
};
