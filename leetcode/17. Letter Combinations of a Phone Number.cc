// Copyright 2017 Qi Wang
// Date: 2017-07-02
// Actually I think the solution on 2016-12-20 is more elegant than this impl.
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> result;
    string str;
    Combinations(digits, 0, str, result);
    return result;
  }
 
 private:
  void Combinations(const string& digits, size_t idx, string& str,
      vector<string>& result) {
    if (digits.size() == idx) {
      result.push_back(str);
    } else {
      for (char c : C_TO_STR[digits[idx]]) {
        str.push_back(c);
        Combinations(digits, idx + 1, str, result);
        str.pop_back();
      }
    }
  }
 
  unordered_map<char, string> C_TO_STR = {
    {'2', "abc"}, {'3', "def"},
    {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
    {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
  };
};

// Method 2
// Date: 2016-12-20
// Refer to the solution in 2014-06
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return vector<string>();
    vector<string> res(1, "");
    string btns[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for (char digit : digits)
      for (int i = res.size() - 1; i >= 0; --i)
        for (int j = btns[digit - '2'].size() - 1; j >=0 ; --j)
          if (j != 0) {
            res.push_back(res[i] + btns[digit - '2'][j]);
          } else {
            res[i] += btns[digit - '2'][j];
          }
    return res;
  }
};

// Method 1
// Date: 2016-12-20
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return vector<string>();
    auto res = dfs(digits, 0);
    for (auto& str : res) reverse(str.begin(), str.end());
    return res;
  }

 private:
  vector<string> dfs(const string& digits, int idx) const {
    if (idx == digits.size()) return vector<string>(1);
    auto ans = dfs(digits, idx + 1);
    string btns[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    for (char c : btns[digits[idx] - '2'])
      for (string str : ans)
        res.push_back(str + c);
    return res;
  }
};

// Date: 2014-06
class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
      vector<string> ret(1, "");
      string letters[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

      for (size_t i = 0; i < digits.size(); ++ i)
      {
        string str = letters[digits[i]-'2'];
        for (int j = ret.size()-1; j >= 0; -- j)
        {
          for (int k = str.size()-1; k >= 0; -- k)
          {
            if (k != 0)
            {
              ret.push_back( ret[j] + str[k] );
            } else
            {
              ret[j] += str[k];
            }
          }
        }
      }

      return ret;
    }
};
