// Copyright 2016 Qi Wang
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