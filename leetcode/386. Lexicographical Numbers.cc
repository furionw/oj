// Copyright 2016 Qi Wang
// Method 3
// Time: about 400+ms
// Refer to: http://bookshadow.com/weblog/2016/08/21/leetcode-lexicographical-numbers/
// Date: 2016-11-18
class Solution {
 public:
  vector<int> lexicalOrder(int n) {
    vector<int> res;
    dfs(1, n, res);
    return res;
  }

 private:
  void dfs(int cur, const int& MAX, vector<int>& vtOut) const {
    vtOut.push_back(cur);
    int cur10 = cur * 10;
    if (cur10 <= MAX) dfs(cur10, MAX, vtOut);
    if (cur < MAX && cur % 10 < 9) dfs(cur + 1, MAX, vtOut);
  }
};

// Copyright 2016 Qi Wang
// Method 2
// Refer to: http://bookshadow.com/weblog/2016/08/21/leetcode-lexicographical-numbers/
// Time: 1000+ms, really slow!
// Date: 2016-11-18
class Solution {
 public:
  vector<int> lexicalOrder(int n) {
    vector<int> res;
    stack<int> resStack;
    resStack.push(1);
    while (!resStack.empty()) {
      int cur = resStack.top();
      resStack.pop();
      res.push_back(cur);
      if (cur < n && cur % 10 < 9) resStack.push(cur + 1);
      if (cur * 10 <= n) resStack.push(cur * 10);
    }
    return res;
  }
};

// Method 1
// Time: about 500+ms
// Date: 2016-11-18
class Solution {
 public:
  vector<int> lexicalOrder(int n) {
    vector<int> res;
    for (int i = 1; i < 10 && i <= n; ++i)
      dfs(i, n, res);
    return res;
  }

 private:
  void dfs(int cur, const int& MAX, vector<int>& vtOut) const {
    vtOut.push_back(cur);
    int cur10 = cur * 10;
    for (int i = 0; i < 10; ++i)
      if (cur10 + i <= MAX)
        dfs(cur10 + i, MAX, vtOut);
  }
};
