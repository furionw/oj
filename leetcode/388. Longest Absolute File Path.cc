// Copyright 2017 Qi Wang
// Date: 2017-01-01
// Method 2: with find_first_of and find_first_not_of
class Solution {
 public:
  int lengthLongestPath(string input) {
    int res = 0;
    stack<int> stk;
    for (size_t i = 0; i < input.size();) {
      size_t cnt = input.find_first_not_of('\t', i) - i;
      // pop the directories, whose files have all been explored
      while (stk.size() > cnt) stk.pop();
      i += cnt;
      // length of file
      size_t wordEnd = input.find_first_of('\n', i);
      cnt = (wordEnd != string::npos ? wordEnd : input.size()) - i;
      stk.push(stk.empty() ? cnt : stk.top() + 1 + cnt);
      if (input.substr(i, cnt).find('.') != string::npos)
        res = max(res, stk.top());
      i += cnt + 1;
    }
    return res;
  }
};


// Date: 2017-01-01
// Method 1
class Solution {
 public:
  int lengthLongestPath(string input) {
    int res = 0;
    stack<int> stk;
    for (size_t i = 0; i < input.size(); ++i) {
      int cnt = 0;
      for (; i < input.size() && input[i] == '\t'; ++i, ++cnt) {}
      while (stk.size() > cnt) stk.pop();
      cnt = 0;
      for (; i < input.size() && input[i] != '\n'; ++i, ++cnt) {}
      stk.push(stk.empty() ? cnt : stk.top() + 1 + cnt);
      if (input.substr(i - cnt, cnt).find('.') != string::npos)
        res = max(res, stk.top());
    }
    return res;
  }
};

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
