// Copyright 2017 Qi Wang
// Date: 2017-07-09
// Refer to: Jinhao's solution
class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty()) return 0;
    int64_t first = 1;
    int64_t second = '*' == s[0] ? 9 : '0' != s[0] ? 1 : 0;
    static constexpr int MOD = 1e9 + 7;
    for (size_t i = 1; i < s.size(); ++i) {
      int second_mul = '*' == s[i] ? 9 : '0' != s[i] ? 1 : 0;
      // 's[i - 1]' == 0, 3, 4, ...
      int first_mul = 0;
      if ('1' == s[i - 1]) {
        first_mul = '*' == s[i] ? 9 : 1;
      } else if ('2' == s[i - 1]) {
        first_mul = '*' == s[i] ? 6 : s[i] <= '6' ? 1 : 0;
      } else if ('*' == s[i - 1]) {
        first_mul = '*' == s[i] ? 15 : s[i] <= '6' ? 2 : 1;
      }
      int64_t third = (first_mul * first + second_mul * second) % MOD;
      first = second;
      second = third;
    }
    return second;
  }
};

// Date: 2017-07-08
class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty() || '0' == s[0]) {
      return 0;
    } else if (s.size() == 1) {
      return '0' != s[0] ? ('*' == s[0] ? 9 : 1) : 0;
    }
    vector<int64_t> dp(s.size() + 1);
    dp[0] = 1;
    dp[1] = '*' == s[0] ? 9 : 1;
    for (size_t i = 1; i < s.size(); ++i) {
      if ('0' == s[i]) {
        if ('0' == s[i - 1] ||
            (IsDigit(s[i - 1]) && stoi(s.substr(i - 1, 2)) > 26)) {
          return 0;
        // 1, 2, *
        } else {
          dp[i + 1] = ('*' == s[i - 1] ? 2 : 1) * dp[i - 1] % MOD;
        }
      } else if ('*' == s[i]) {
        // 1
        if ('1' == s[i - 1]) {
          dp[i + 1] = (9 * dp[i] + 9 * dp[i - 1]) % MOD;
        // 2
        } else if ('2' == s[i - 1]) {
          dp[i + 1] = (9 * dp[i] + 6 * dp[i - 1]) % MOD;
        // *
        } else if ('*' == s[i - 1]) {
          dp[i + 1] = (9 * dp[i] + 15 * dp[i - 1]) % MOD;
        // s[i - 1] == 0, 3, 4, ...
        } else {
          dp[i + 1] = (9 * dp[i]) % MOD;
        }
      // s[i] == 1, 2, 3, 4, 5, 6, 7, 8, 9
      } else {
        if ('*' == s[i - 1]) {
          if (s[i] <= '6') {
            dp[i + 1] = (dp[i] + 2 * dp[i - 1]) % MOD;
          } else {
            dp[i + 1] = (dp[i] + dp[i - 1]) % MOD;
          }
        } else {
          dp[i + 1] = (dp[i] +
              ('0' != s[i - 1] && stoi(s.substr(i - 1, 2)) <= 26 ? dp[i - 1] : 0)) % MOD;
        }
      }
    }
    return dp.back();
  }

 private:
  bool IsDigit(char c) const {
    return '0' <= c && c <= '9';
  }

  static const int MOD = 1e9 + 7;
};
