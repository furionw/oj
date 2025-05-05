// 2025-05-03
class Solution {
 public:
  int compress(vector<char>& chars) {
    int i = 0;
    for (int j = 0; j < chars.size(); ++j) {
      int k = j;
      for (; k + 1 < chars.size() && chars[k + 1] == chars[k]; ++k) {}
      chars[i] = chars[j];
      ++i;
      if (k == j) {
        continue;
      }
      string cnt = to_string(k - j + 1);
      j = k;
      for (auto c : cnt) {
        chars[i] = c;
        ++i;
      }
    }
    return i;
  }
};
