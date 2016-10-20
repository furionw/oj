// Copyright 2016 Qi Wang
// Date: 2016-10-04
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    auto noteCnt = getCnt(ransomNote), magCnt = getCnt(magazine);
    for (auto &p : noteCnt)
      if (magCnt[p.first] < noteCnt[p.first]) return false;
    return true;
  }

 private:
  inline map<char, int> getCnt(const string& str) const {
    map<char, int> cnt;
    for (char c : str)
      ++cnt[c];
    return cnt;
  }
};
