// 2025-07-18
class Solution {
 public:
  vector<string> expand(string s) {
    dfs(s, 0);
    return result;
  }

 private:
  void dfs(const string& s, int idx) {
    if (idx == s.size()) {
      result.push_back(cur);
      return;
    }
    vector<char> options;
    if (s[idx] != '{') {
      options.push_back(s[idx]);
      ++idx;
    } else {
      int end = s.find('}', idx + 1);
      for (int i = idx + 1; i < end; i += 2) {
        options.push_back(s[i]);
      }
      idx = end + 1;
    }
    sort(options.begin(), options.end());
    for (char c : options) {
      cur += c;
      dfs(s, idx);
      cur.pop_back();
    }
  }

  vector<string> result;
  string cur;
};
