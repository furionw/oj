#include <iostream>
#include <string>
#include <vector>

using namespace std;

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