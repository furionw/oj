class Solution 
{
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        for (int i = 1; i<=9 && k>0 && i<=n; ++ i)
        {
        	vector<int> cur(1, i);
        	gao(i+1, k-1, n-i, cur);
        }
        return ret;
    }

private:
	void gao(int begin, int k, int n, vector<int>& cur)
	{
		if (k==0 && n==0)
		{
			ret.push_back(cur);
			return;
		}
		for (int i = begin; i<=9 && k>0 && i<=n; ++ i)
		{
			cur.push_back(i);
			gao(i+1, k-1, n-i, tmp);
			cur.pop_back();
		}
	}

	vector<vector<int>> ret;
};