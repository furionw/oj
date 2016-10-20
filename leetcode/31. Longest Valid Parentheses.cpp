#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution 
{
public:
	int longestValidParentheses(string s) 
	{
		vector<int> dp(s.size(), 0);

		for (int i = 1; i < s.size(); ++ i)
		{
			if (s[i]==')' && i-1-dp[i-1]>=0 && s[i-1-dp[i-1]]=='(') // 边界检查
			{
				dp[i] = dp[i-1]+2; 
				if (i-dp[i] >= 0)  // 边界检查
				{
					dp[i] = dp[i] + dp[i-dp[i]];
				}
			}
		}

		return s.empty()? 0: *max_element(dp.begin(), dp.end());
	}
};

int main()
{
	Solution a;
	cout << a.longestValidParentheses("())()(");

	return 0;
}
