// 2025-06-11
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    bitset<301> dp;
    dp[0] = true;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (!dp[i]) {
        continue;
      }
      for (const auto& word: wordDict) {
        if (equal(s, i, word)) {
          dp[i + word.size()] = true;
        }
      }
    }
    return dp[n];
  }

 private:
  bool equal(const string& s, int i, const string& word) const {
    for (char c : word) {
      if (i == s.size() || s[i] != c) {
        return false;
      }
      ++i;
    }
    return true;
  }
};

// Date: 2017-11-04
// Case 1: "", []
//   return true
// Case 2: "leetcode", ["leet", "code"]
//   i == 4, 
//     j == 0, dp[i] = dp[4] = true
//   i == 8,
//     j == 4, dp[i] = dp[8] = true
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    unordered_set<string> str_set(wordDict.begin(), wordDict.end());
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 0; !dp[i] && j < i; ++j) {
        dp[i] = dp[j] && str_set.count(s.substr(j, i - j));
      }
    }
    return dp.back();
  }
};
 
// Date: 2017-08-15
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 0; !dp[i] && j < wordDict.size(); ++j) {
        int len = wordDict[j].size();
        dp[i] = i - len >= 0 && dp[i - len] &&
                s.substr(i - len, len) == wordDict[j];
      }
    }
    return dp.back();
  }
};

// Date: 2017-08-12
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 0; !dp[i] && j < i; ++j) {
        dp[i] = dp[j] && find(wordDict.begin(), wordDict.end(),
                              s.substr(j, i - j)) != wordDict.end();
      }
    }
    return dp.back();
  }
};

// Date: 2017-07-22
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (size_t i = 0; i < s.size(); ++i) {
      if (!dp[i]) continue;
      for (const string& word : wordDict) {
        if (word == s.substr(i, word.size())) {
          dp[i + word.size()] = true;
        }
      }
    }
    return dp.back();
  }
};

// Date: 2017-07-21
// TLE
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    if (s.empty()) return true;
    unordered_set<string> dict;
    for (const string& word : wordDict) {
      dict.insert(word);
    }
    return WordBreak(s, dict);
  }

 private:
  bool WordBreak(const string& str, const unordered_set<string>& dict) const {
    if (str.empty()) return true;
    for (size_t len = 1; len <= str.size(); ++len) {
      if (dict.find(str.substr(0, len)) != dict.end()
          && WordBreak(str.substr(len), dict))
        return true;
    }
    return false;
  }
};

// Date: 2016-10-10
class Solution {
 public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    vector<int> dp(s.size(), false);
    for (size_t i = 0; i < s.size(); ++i) {
      dp[i] = dict.find(s.substr(0, i + 1)) != dict.end();
      for (size_t j = 0; j < i && !dp[i]; ++j)
        dp[i] = dp[j] && dict.find(s.substr(j + 1, i - j)) != dict.end();
    }
    return dp.back();
  }
};

// Date: 2015-03
class Solution {
 public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (size_t i = 0; i < s.size(); ++ i) {
      if (dp[i] == true) {
        for (size_t length = 1; i + length <= s.size(); ++ length) {
          dp[i + length] = dp[i + length]? true: 
               dict.find(s.substr(i, length))!=dict.end();
        }
      }
    }
    return dp[s.size()];
  }
};
