// Copyright 2017 Qi Wang
// Date: 2017-11-04
// Case 1: "123"
class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;
    unordered_set<string> nums;
    for (int i = 1; i <= 26; ++i) {
      nums.insert(to_string(i));
    }
    int first = 1, second = 1;
    for (int i = 1; i < s.size(); ++i) {
      int next = nums.count(s.substr(i - 1, 2)) * first +
                 nums.count(s.substr(i, 1)) * second;
      // Revisited on 2017-11-11.
      // Here we assume first and second are non-zero, if the next is
      // zero, we can ensure that the given string cannot be decoded.
      if (next == 0) return 0;
      first = second;
      second = next;
    }
    return second;
  }
};

// Date: 2017-08-29
// Case 1: "12"
class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty()) return 0;
    unordered_set<string> nums;
    for (int i = 1; i <= 26; ++i) nums.insert(to_string(i));
    auto ValidNumber = [&nums](const string& num) {
      return nums.find(num) != nums.end();
    };
    vector<int> dp(s.size(), 0);
    for (int i = 0; i < s.size(); ++i) {
      if (i == 0) {
        dp[i] = s[i] != '0';
      } else if (i == 1) {
        dp[i] = (s[i] != '0') + ValidNumber(s.substr(0, 2));
      } else {
        dp[i] = (s[i] != '0' ? dp[i - 1] : 0) +
                (ValidNumber(s.substr(i - 1, 2)) ? dp[i - 2] : 0);
      }
      if (dp[i] == 0) {
        return 0;
      }
    }
    return dp.back();
  }
};

// Date: 2017-07-07
// Method 2: DP
class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty() || '0' == s[0]) {
      return 0;
    } else if (s.size() == 1) {
      return '0' != s[0];
    }
    vector<int> dp(s.size() + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (size_t i = 1; i < s.size(); ++i) {
      if ('0' == s[i]) {
        if ('0' == s[i - 1] || stoi(s.substr(i - 1, 2)) > 26) {
          return 0;
        } else {
          dp[i + 1] = dp[i - 1];
        }
      } else {
        dp[i + 1] = dp[i] +
            ('0' != s[i - 1] && stoi(s.substr(i - 1, 2)) <= 26 ? dp[i - 1] : 0);
      }
    }
    return dp.back();
  }
};

// Date: 2017-07-07
// Method 1: TLE
class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty()) {
      return 0;
    }
    for (int i = 1; i <= 26; ++i) {
      chars[i] = 'A' + i;
    }
    unordered_set<string> result;
    Decode(s, 0, "", &result);
    return result.size();
  }

 private:
  void Decode(const string& s, size_t idx, string cur,
      unordered_set<string>* result) const {
    if (s.size() == idx) {
      result->insert(cur);
      return;
    }
    if ('0' == s[idx]) {
      return;
    } else {
      Decode(s, idx + 1, cur + chars[s[idx] - '0'], result);
      if (idx + 1 < s.size()) {
        int num = stoi(s.substr(idx, 2));
        if (num <= 26) {
          Decode(s, idx + 2, cur + chars[num], result);
        }
      }
    }
  }

  vector<char> chars = vector<char>(27);
};

class Solution 
{
public:
    int numDecodings(string s) 
    {
      if ( s.empty() )
      {
        return 0;
      } else if ( s[0] == '0' )
      {
        return 0;
      } else if ( s.size() == 1)
      {
        return 1;
      }

      vector<int> dp(s.size(), 1);
      if (s[1] == '0')
      {
        if (s[0]!='1' && s[0]!='2')
        {
          return 0;
        } else
        {
          dp[1] = dp[0];
        }
      } else 
      {
        if (2<s.size() && s[2]=='0')
        {
          dp[1] = dp[0];
        } else
        {
        dp[1] = dp[0] + (string_to_int(s.substr(0, 2))<=26? 1: 0);
        }
      }
      for (size_t i = 2; i < s.size(); ++ i)
      {
        if (s[i]=='0')
        {
          if (s[i-1]!='1' && s[i-1]!='2')
          {
            return 0;
          } else
          {
            dp[i] = dp[i-1];
          }
        } else // 自身非0
        {
          if (s[i-1] == '0')
          {
            dp[i] = dp[i-1];
          } else if (i+1<s.size() && s[i+1]=='0')
          {
            dp[i] = dp[i-1];
          } else
          {
          dp[i] = dp[i-1] + (string_to_int(s.substr(i-1, 2))<=26? dp[i-2]: 0);
          }
        }
      }

      return dp.back();
    }
private:
  int string_to_int(const string& s)
  {
    int ret;
    stringstream ss;
    ss << s;
    ss >> ret;
    return ret;
  }
};
