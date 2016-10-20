class Solution {
 public: 
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;

    string res;
    int offset = 2 * numRows - 2;
    for (int i = 0; i < numRows; ++ i)
      for (int j = 0; ; ++ j) {
        int idx;
        if (i == 0 || i == numRows - 1)
          idx = j * offset + i;
        else
          idx = (j + 1) / 2 * offset + (j % 2 == 0? i: -i);
        if (idx < s.size())
          res += s[idx];
        else
          break;
      }
      return res;
  }
};
