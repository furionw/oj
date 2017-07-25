// Copyright 2017 Qi Wang
// Date: 2017-07-24
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size()) return {};
    int cnts[26];
    memset(cnts, 0, sizeof cnts);
    for (char c : p) {
      ++cnts[c - 'a'];
    }
    for (size_t i = 0; i < p.size(); ++i) {
      --cnts[s[i] - 'a'];
    }
    vector<int> result;
    if (count(cnts, cnts + 26, 0) == 26) {
      result.push_back(0);
    }
    for (size_t i = p.size(); i < s.size(); ++i) {
      ++cnts[s[i - p.size()] - 'a'];
      --cnts[s[i] - 'a'];
      if (count(cnts, cnts + 26, 0) == 26) {
        result.push_back(i - p.size() + 1);
      }
    }
    return result;
  }
};

// Date: 2016-10-30
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    if (p.size() > s.size()) return vector<int>();
    // init
    size_t sz = s.size() - p.size() + 1;
    std::unique_ptr<int[][CHARACTER_SZ]> dp(new int[sz][CHARACTER_SZ]);
    vector<int> cnt(CHARACTER_SZ, 0);
    fill(dp[0], dp[0] + CHARACTER_SZ, 0);
    // DP init
    for (size_t i = 0; i < p.size(); ++i) {
      ++dp[0][s[i] - 'a'];
      ++cnt[p[i] - 'a'];
    }
    vector<int> res;
    if (judge(dp[0], cnt.data())) res.push_back(0);
    // DP deduct
    for (size_t i = 1; i < sz; ++i) {
      copy(dp[i - 1], dp[i - 1] + CHARACTER_SZ, dp[i]);
      --dp[i][s[i - 1] - 'a'];
      ++dp[i][s[i + p.size() - 1] - 'a'];
      // put judge in this loop to boost up processing,
      // via spacial locality and enlarging the loop block
      if (judge(dp[i], cnt.data())) res.push_back(i);
    }
    return res;
  }

 private:
  inline bool judge(int a[], int b[]) const {
    // set bound as 25 instead of 26 here.
    for (int i = 0; i < CHARACTER_SZ - 1; ++i)
      if (a[i] != b[i]) return false;
    return true;
  }

  static constexpr int CHARACTER_SZ = 26;
};
