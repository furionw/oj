// Copyright 2016 Qi Wang
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
