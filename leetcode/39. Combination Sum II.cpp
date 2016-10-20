#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) 
	{
		sort(candidates.begin(), candidates.end());
		for (size_t i = 0; i < candidates.size(); ++ i)
		{
			if (i==0 || candidates[i]!=candidates[i-1])
			{
				num.push_back( candidates[i] );
				cnt.push_back( 1 );
			} else
			{
				++ cnt[cnt.size()-1];
			}
		}
		vector<int> now;
		dfs(now, 0, target);
		return ret;
	}
private:
	vector<int> num;
	vector<int> cnt;
	vector<vector<int> > ret;
	void dfs(vector<int>& now, size_t index, int remain)
	{
		for (size_t i = index; i < num.size(); ++ i)
		{
			if (num[i] > remain)
			{
				break;
			} else
			{
				int cur = remain;
				for (int j = 0; j<cnt[i] && num[i]<=cur; ++ j)
				{
					cur -= num[i];
					now.push_back( num[i] );
					dfs(now, i+1, cur);
				}
				if (cur == 0)
				{
					ret.push_back( now );
				}
				while (cur != remain)
				{
					now.pop_back();
					cur += num[i];
				}
			}
		}
	}
};

int main()
{
	vector<int> num;
	num.push_back(10);
	num.push_back(1);
	num.push_back(2);
	num.push_back(7);
	num.push_back(6);
	num.push_back(1);
	num.push_back(5);
	Solution a;
	a.combinationSum2(num, 8);

	return 0;
}