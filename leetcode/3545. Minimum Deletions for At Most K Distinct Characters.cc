// 2025-06-03
class Solution {
 public:
  int minDeletion(string s, int k) {
    vector<int> cnts(26, 0);
    for (char c : s) {
      ++cnts[c - 'a'];
    }
    sort(cnts.begin(), cnts.end());
    auto it = upper_bound(cnts.begin(), cnts.end(), 0);
    int result = 0;
    for (int i = it - cnts.begin(); 26 - i > k; ++i) {
      result += cnts[i];
    }
    return result;
  }
};
