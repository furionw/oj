// Date: 2022-10-08
class Solution {
 public:
  string robotWithString(string s) {
    int n = s.size();
    string minFromBack = s;
    for (int i = n - 2; i >= 0; --i) {
      minFromBack[i] = min(s[i], minFromBack[i + 1]);
    }
    minFromBack.back() += 1;
    string p;
    string t;
    stack<char> stk;
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && stk.top() <= s[i] && stk.top() <= minFromBack[i]) {
        p += stk.top();
        stk.pop();
      }
      if (s[i] == minFromBack[i]) {
        p += s[i];
        continue;
      }
      stk.push(s[i]);
    }
    for (; !stk.empty(); stk.pop()) {
      p += stk.top();
    }
    return p;
  }
};