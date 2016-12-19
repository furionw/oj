// Copyright 2016 Qi Wang
// Date: 2016-12-19
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    int len = 0;
    while (true) {
      if (len == strs.front().size()) break;
      char c = strs.front()[len];
      if (any_of(strs.begin(), strs.end(), [c, len](const string& str) {
        return str.size() < len || str[len] != c;
      })) break;
      ++len;
    }
    return strs.front().substr(0, len);
  }
};

// Date: 2016-11-07
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    size_t maxLen = INT_MAX;
    for (const auto& str : strs) maxLen = min(maxLen, str.size());
    size_t len = 1;
    for (; len <= maxLen; ++len) {
      char c = strs[0][len - 1];
      for (size_t i = 1; i < strs.size(); ++i)
        if (strs[i][len - 1] != c)
          return strs[0].substr(0, len - 1);
    }
    return strs[0].substr(0, len - 1);
  }
};

// Date: 2014-05
class Solution 
{
public:
    string longestCommonPrefix(vector<string> &strs) 
    {
		if (strs.size() == 0)
		{
			return string();
		} else if (strs.size() == 1)
		{
			return strs[0];
		}

    	int length = INT_MAX;

    	for (int  i = 0; i < strs.size()-1; ++ i)
    	{
    		size_t j = 0;
    		while( j<strs[i].size() && j<strs[i+1].size() 
    			&& j<length && strs[i][j] == strs[i+1][j]) 
    		{
    			++ j;
    		}
    		length = length<j? length: j;
    	}

    	return strs[0].substr(0, length);
    }
};