// Copyright 2016 Qi Wang
// Date: 2016-12-27
class Solution {
 public:
  vector<string> generatePalindromes(string s) {
    auto cnts = countChar(s);
    int charWithOddCnt = INT_MAX;
    string half;
    for (auto& cnt : cnts) {
      // counter is an odd number
      if (cnt.second & 1 == 1) {
        // first character appearing odd times
        if (charWithOddCnt == INT_MAX) {
          charWithOddCnt = cnt.first;
        // second character appearing odd times, thus we cannot form palindromes
        } else {
          return vector<string>();
        }
      }
      // apend half of those same characters at the end of "half"
      half += string(cnt.second >> 1, cnt.first);
    }
    vector<string> res;
    do {
      string rHalf = half;
      reverse(rHalf.begin(), rHalf.end()); 
      // There is a character appearsing odd times.
      if (charWithOddCnt != INT_MAX) {
        res.push_back(half + static_cast<char>(charWithOddCnt) + rHalf);
      } else {
        res.push_back(half + rHalf);
      }
    } while (nextPermutation(half));
    return res;
  }

 private:
  map<char, int> countChar(const string& s) const {
    map<char, int> cnts;
    for (char c : s) ++cnts[c];
    return cnts;
  }

  bool nextPermutation(string& str) {
    if (str.size() <= 1) return false;
    int n = static_cast<int>(str.size());
    for (int i = n - 2; i >= 0; --i) {
      for (int j = n - 1; j > i; --j) {
        if (str[j] > str[i]) {
          swap(str[j], str[i]);
          reverse(str.begin() + i + 1, str.end());
          return true;
        }
      }
    }
    return false;
  }
};
