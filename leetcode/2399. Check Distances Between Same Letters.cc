// Date: 2022-10-15
class Solution {
 public:
  bool checkDistances(string s, vector<int>& distance) {
    unordered_map<char, int> lastIdxByChar;
    for (size_t i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (lastIdxByChar.count(c)) {
        int actualDis = i - lastIdxByChar[c] - 1;
        if (actualDis != distance[c - 'a']) {
          return false;
        }
      }
      lastIdxByChar[c] = i;
    }
    return true;
  }
};
