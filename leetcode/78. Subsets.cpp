class Solution 
{
public:
    vector<vector<int> > subsets(vector<int> &S) 
    {
    	sort(S.begin(), S.end());    
    	for (size_t i = 0; i <= S.size(); ++ i)
    	{
    		vector<int> now;
    		gao(now, 0, S, i);
    	}
    	return ret;
    }
private:
	void gao(vector<int>& now, size_t start, vector<int>& S, size_t k)
	{
		if (now.size() == k)
		{
			ret.push_back(now);
			return ;
		}
		for (size_t i = start; i < S.size(); ++ i)
		{
			now.push_back(S[i]);
			gao(now, i+1, S, k);
			now.pop_back();
		}
	}
	vector<vector<int>> ret;
};