// Copyright 2016 Qi Wang
// Date: 2016-10-28
class Solution {
 public:
  string decodeString(string str) {
    size_t idx = 0;
    return decodeString(1, str, idx);
  }

 private:
  string decodeString(int times, const string& str, size_t& idx) const {
    string encodeStr;
    for (; str[idx] != ']' && idx < str.size(); ++idx) {
      if (isDigit(str[idx])) {
        size_t digitBegin = idx++;
        for (; isDigit(str[idx]); ++idx) {}
        int t = stoi(str.substr(digitBegin, idx - digitBegin));
        encodeStr += decodeString(t, str, ++idx);
        cout << encodeStr << endl;
        cout << str[idx] << endl;
      } else {
        // trivial character. We just append it to the end of the "encodeStr"
        encodeStr += str[idx];
      }
    }
    string res;
    while (times--) res += encodeStr;
    cout << "res: " << res << endl;
    return res;
  }

  inline bool isDigit(char c) const {
    return '0' <= c && c <= '9';
  }
};
