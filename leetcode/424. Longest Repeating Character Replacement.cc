// Copyright 2016 Qi Wang
// Refer to: https://boweihe.me/2016/10/24/leetcode-424-longest-repeating-character-replacement/
// Date: 2016-12-01
class Solution {
 public:
  int characterReplacement(string s, int k) {
    int cnt[26] = {0}, most = 0;
    for (int begin = 0, end = 0; end < s.size(); ++end) {
      // Try to widen the window size by updating "most"
      most = max(most, ++cnt[s[end] - OFFSET]);
      if (most + k == end - begin) {
        --cnt[s[begin] - OFFSET];
        ++begin;
      }
    }
    return most + k < s.size() ? most + k : s.size();
  }

 private:
  static constexpr char OFFSET = 'A';
};
