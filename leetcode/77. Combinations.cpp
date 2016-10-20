class Solution 
{
public:
    vector<vector<int> > combine(int n, int k) 
    {
        vector<int> now;
        gao(now, 1, n, k);
        return ret;
    }
private:
	void gao(vector<int>& now, int start, int n, int k)
	{
		if (now.size() == k)
		{
			ret.push_back(now);
		}
		for (int i = start; i <= n; ++ i)
		{
			now.push_back(i);
			gao(now, i+1, n, k);
			now.pop_back();
		}
	}
	vector<vector<int>> ret;
};