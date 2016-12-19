// Copyright 2016 Qi Wang
// Date: 2016-12-19
class Solution {
 public:
  string convert(string s, int numRows) {
    // ill input
    if (numRows == 0) return "";
    // trivial case
    if (numRows == 1) return s;
    string rows[numRows];
    int pattern = (numRows << 1) - 2, cnt = 0;
    for (char c : s) {
      rows[cnt < numRows ? cnt : pattern - cnt] += c;
      cnt = ++cnt != pattern ? cnt : 0;
    }
    return accumulate(rows, rows + numRows, string());
  }
};

// Date: 2016-03
// Revisited on 2016-12-19
// This implmentation is fater 'cause it doesn't allocate the string array
class Solution {
 public: 
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    string res;
    int offset = 2 * numRows - 2;
    for (int row = 0; row < numRows; ++row) {
      for (int j = 0; ; ++j) {
        int idx = row == 0 || row == numRows - 1
            ? j * offset + row
            : (j + 1 >> 1) * offset + ((j & 1) == 0 ? row : -row);
        if (idx < s.size()) {
          res += s[idx];
        } else {
          break;
        }
      }
    }
    return res;
  }
};

// Date: 2014-06
class Solution 
{
public:
    string convert(string s, int nRows) 
    {
    if (nRows == 1)
    {
      return s;
    }

      string ret;
    vector<string> rows(nRows);
    int interval = 2*nRows-2;

    for (size_t i = 0; i < s.size(); ++ i)
    {
      if (i % interval < nRows)
      {
        rows[i%interval] += s[i];
      } else
      {
        rows[nRows-1-(i%interval-nRows+1)] += s[i];
      }
    }
    for (size_t i = 0; i < nRows; ++ i)
    {
      ret += rows[i];
    }

    return ret;
    }
};