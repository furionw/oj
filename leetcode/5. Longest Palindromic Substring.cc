// Copyright 2017 Qi Wang
// Date: 2017-08-23
// Refer to: https://discuss.leetcode.com/topic/12187/simple-c-solution-8ms-13-lines
// Time complexity: O(N^2)
class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() <= 1) return s;
    int result_idx = 0, result_len = 1;
    for (int i = 0; i < s.size();) {
      if (s.size() - i < result_len / 2) break;
      int j = i, k = i;
      for (; k + 1 < s.size() && s[k] == s[k + 1]; ++k) {}
      i = k + 1;
      while (j - 1 >= 0 && k + 1 < s.size() && s[j - 1] == s[k + 1]) {
        --j;
        ++k;
      }
      int new_len = k - j + 1;
      if (new_len > result_len) {
        result_len = new_len;
        result_idx = j;
      }
    }
    return s.substr(result_idx, result_len);
  }
};

// Manacher algorithm finding longest palindrome substring in O(n) time
// Date: 2016-10-04
class Solution {
 public:
  string longestPalindrome(string s) {
    string str(2 * s.size() + 1, 0);
    for (size_t i = 0; i < s.size(); ++i)
      str[2 * i + 1] = s[i];
    vector<size_t> p(str.size(), 0);
    size_t mirrorRight = 0, mirrorCenter;
    size_t maxCenter = 0;
    for (size_t i = 1; i < str.size(); ++i) {
      p[i] = mirrorRight > i ? min(mirrorRight - i, p[2 * mirrorCenter - i]): 0;
      for (; i + p[i] + 1 < str.size() && i - p[i] - 1 >= 0
          && str[i + p[i] + 1] == str[i - p[i] - 1]; ++p[i]) {}
      if (i + p[i] > mirrorRight) {
        mirrorRight = i + p[i];
        mirrorCenter = i;
      }
      // update maxCenter
      maxCenter = p[i] > p[maxCenter] ? i : maxCenter;
    }
    return s.substr((maxCenter - p[maxCenter]) >> 1, p[maxCenter]);
  }
};

// old one
class Solution 
{
public:
	string longestPalindrome(string s) 
	{
		string str(2*s.size()+1, 0);
		// str
		for (size_t i = 0, j = 0; i < str.size(); ++ i)
		{
			if (i % 2 == 0)
			{
				str[i] = 0;
			} else
			{
				str[i] = s[j ++];
			}
		}	
		// p
		int mx = 0, id, max_length=0, max_id; 
		vector<int> p(2*s.size()+1, 0);
		for (int i = 0; i < str.size(); ++ i)
		{
			p[i] = mx>i? min(p[2*id-i], mx-i): 0;
			for ( ; i-p[i]-1>=0 && i+p[i]+1<str.size() 
				&& str[i-p[i]-1] == str[i+p[i]+1]; ++ p[i]) {}			
			if (i + p[i] > mx)
			{
				mx = i + p[i];
				id = i;
			}
			if (max_length < p[i])
			{
				max_length = p[i];
				max_id = i;
			}
		}

		return s.substr((max_id-p[max_id])/2, p[max_id]);
	}
};

int main()
{
	Solution s;
	cout << s.longestPalindrome( string("a") );
	//	cout << string("a").substr(0, 2);

	return 0;
}