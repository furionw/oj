// 2025-06-14
class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    vector<vector<string>> dp(n + 1, vector<string>{});
    dp[0].push_back("");
    for (int i = 1; i <= n; ++i) {
      // Looking for words that end with s[i - 1]
      for (const auto& word: wordDict) {
        int idx = (i - 1) - int(word.size()) + 1;
        if (idx < 0 || !equal(s, idx, word)) {
          continue;
        }
        for (const auto& prefix : dp[idx]) {
          if (prefix.empty()) {
            dp[i].push_back(word);
          } else {
            dp[i].push_back(prefix + " " + word);
          }
        }
      }
    }
    return dp[n];
  }

 private:
  bool equal(const string& s, int idx, const string& word) const {
    // e.g. s = "0123456", s.size() = 7, idx = 4, word = "456"
    // idx + word.size() = 7 == s.size(). true
    if (idx + word.size() > s.size()) {
      return false;
    }
    for (char c : word) {
      if (s[idx] != c) {
        return false;
      }
      ++idx;
    }
    return true;
  }
};


// Copyright 2017 Qi Wang
// Date: 2017-11-04
class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    if (s.empty()) return {};
    vector<list<string>> dp(s.size() + 1);
    dp[0].push_back("");
    for (int i = 1; i <= s.size(); ++i) {
      for (const string& word : wordDict) {
        int len = word.size();
        if (i - len >= 0 && !dp[i - len].empty() &&
            s.substr(i - len, len) == word) {
          dp[i].push_back(word);
        }
      }
    }
    if (dp.back().empty()) return {};
    vector<string> result;
    CollectResult(dp, dp.size() - 1, "", &result);
    return result;
  }
 
 private:
  void CollectResult(const vector<list<string>>& dp, int idx, string cur,
      vector<string>* result) const {
    if (idx == 0) {
      result->push_back(cur);
      return;
    }
    for (const string& str : dp[idx]) {
      CollectResult(dp, idx - str.size(),
                    str + (idx == dp.size() - 1 ? "" : " ") + cur, result);
    }
  }
};

// Date: 2017-08-12
// TLE
// Please refer to the solution on 2016-10-10
class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<vector<string>> dp(s.size() + 1);
    dp[0].push_back("");
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        const auto& word = s.substr(j, i - j);
        if (dp[j].empty() || !ContainsElement(dict, word)) continue;
        for (const auto& prefix : dp[j]) {
          dp[i].push_back(prefix + (prefix.empty() ? "" : " ") + word);
        }
      }
    }
    return dp.back();
  }

 private:
  bool ContainsElement(const unordered_set<string>& dict,
                       const string& word) const {
    return find(dict.begin(), dict.end(), word) != dict.end();
  }
};

// Date: 2016-10-10
class Solution {
 public:
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<vector<string>> dp(s.size() + 1);
    dp[0].emplace_back("");
    for (size_t i = 0; i < s.size(); ++i) {
      if (dp[i].empty()) continue;
      for (size_t len = 1; i + len <= s.size(); ++len)
        if (dict.find(s.substr(i, len)) != dict.end())
          dp[i + len].push_back(s.substr(i, len));
    }
    vector<string> res;
    recursive(dp, s.size(), "", res);
    return res;
  }
 private:
  void recursive(const vector<vector<string>>& dp, size_t cur,
    string str, vector<string>& res) {
    if (cur == 0) {
      res.push_back(str);
      return;
    }
    for (auto it = dp[cur].begin(); it != dp[cur].end(); ++it)
    recursive(dp, cur - it->size(), str.empty() ? *it : *it + " " + str, res);
  }
};

// DP + DFS
// Date: 2015-03
class Solution
{
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict)
	{
		vector<vector<string>> dp(s.size()+1);
		dp[0].push_back(string(""));

		for (size_t i = 0; i < s.size(); ++ i)
		{
			if (dp[i].empty() == true)
			{
				continue;
			}
			for (size_t length = 1; i + length <= s.size(); ++ length)
			{
				if (dict.find(s.substr(i, length)) == dict.end())
				{
					continue;
				}
				dp[i + length].push_back(s.substr(i, length));
			}
		}
		dfs(string(), dp, s.size());

		return ret;
	}

private:
	void dfs(string str, vector<vector<string>>& dp, size_t now)
	{
		if (now == 0)
		{
			ret.push_back(str);
			return ;
		}
		for (auto it = dp[now].begin(); it != dp[now].end(); ++ it)
		{
			string new_str = (str.empty()? *it: *it + " " + str);
			dfs(new_str, dp, now - it->size());
		}
	}

	vector<string> ret;
};

// TLE
// Date: 2015-03
class Solution
{
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict)
	{
		for (size_t length = 1; length <= s.size(); ++ length)
		{
			recursive(0, length, string(), s, dict);
		}

		return ret;
	}

private:
	void recursive(size_t begin, size_t length, string now, string& s, unordered_set<string>& dict)
	{	
		if (dict.find(s.substr(begin, length)) == dict.end())
		{
			return ;
		}
		now += (begin==0? s.substr(begin, length): string(" ") + s.substr(begin, length));
		size_t next = begin + length;
		if (next == s.size())
		{
			ret.push_back(now);
		}
		for (size_t length = 1; next + length <= s.size(); ++ length)
		{
			recursive(next, length, now, s, dict);
		}
	}

	vector<string> ret;
};

// Memory Limit Exceed
// Date: 2015-03
class Solution
{
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict)
	{
		vector<vector<string>> ret(s.size() + 1);
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;

		for (size_t i = 0; i < s.size(); ++i)
		{
			if (dp[i] == false)
			{
				continue;
			}
			for (size_t length = 1; i + length <= s.size(); ++length)
			{
				if (dict.find(s.substr(i, length)) == dict.end())
				{
					continue;
				}
				dp[i + length] = true;
				if (i == 0)
				{
					ret[i + length].push_back(s.substr(i, length));
				}
				else
				{
					for (auto it = ret[i].begin(); it != ret[i].end(); ++it)
					{
						ret[i + length].push_back(*it + " " + s.substr(i, length));
					}
				}
			}
			ret[i].clear();
		}
		return ret[s.size()];
	}
};
