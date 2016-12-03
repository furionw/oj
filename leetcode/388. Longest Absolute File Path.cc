// Copyright 2016 Qi Wang
// Date: 2016-12-03
class Solution {
 public:
  int lengthLongestPath(string input) {
    cout << input << endl;
    int res = 0;
    vector<int> lens(1, -1);
    for (size_t i = 0; i < input.size(); ++i) {
      int lvl = 1;
      // We guarantee it's \t, instead of \n
      for (; i < input.size() && input[i] == '\t'; ++i) ++lvl;
      // Calculate length
      int len = 0;
      bool findDot = false, findExt = false;
      for (; i < input.size() && input[i] != '\n'; ++i) {
        if (!findDot && input[i] == '.') findDot = true;
        // For now we don't introduce findExt here, assuming the input is well-formed
        // if (findDot && input[i] != '.') findExt = true;
        ++len;
      }
      while (lvl < lens.size()) lens.pop_back();
      // File
      if (findDot) {
        res = max(res, lens.back() + 1 + len);
      // dir
      } else {
        lens.push_back(lens.back() + 1 + len);
      }
    }
    return res;
  }
};
