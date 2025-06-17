// 2025-06-16
class Solution {
 public:
  string reverseOnlyLetters(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      if (!letter(s[l])) {
        ++l;
        continue;
      }
      if (!letter(s[r])) {
        --r;
        continue;
      }
      swap(s[l], s[r]);
      ++l;
      --r;
    }
    return s;
  }

 private:
  bool letter(char c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
  }
};
