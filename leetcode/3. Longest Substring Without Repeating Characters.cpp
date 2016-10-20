#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
	int lengthOfLongestSubstring(string s) 
	{
		if (s.size()==0)
		{
			return 0;
		}

		vector<int> dp(s.size(), 0);
		int max=1;

		dp[0] = 1;
		for (int i = 1; i < s.size(); ++ i)
		{
			for (int j = i-1; j>=i-dp[i-1]; -- j)
			{
				if (s[i] == s[j])
				{
					dp[i] = i-j;
					break;
				}
			}
			dp[i] = dp[i]==0? dp[i-1]+1: dp[i];
			max = dp[i]>max? dp[i]: max;
		}

		return max;
	}
};

int main()
{
	Solution a;
	a.lengthOfLongestSubstring(string("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco"));

	return 0;
}