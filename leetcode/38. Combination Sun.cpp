class Solution 
{
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
    {
    	sort(candidates.begin(), candidates.end());
    	for (size_t i = 0; i < candidates.size(); ++ i)
    	{
    		if (i==0 || candidates[i]!=candidates[i-1])
    		{
    			m_candidates.push_back( candidates[i] );
    		}
    	}
    	vector<int> now;
    	dfs(now, target, 0);
    	return ret;
    }
private:
	vector<int> m_candidates;
	vector<vector<int> > ret;
	
	void dfs(vector<int>& now, int remain, int index)
	{
		for (int i = index; i<m_candidates.size(); ++ i)
		{
			if (m_candidates[i] > remain)
			{
				break;
			} else 
			{
				int cur = remain;
				while (m_candidates[i] <= cur)
				{
					now.push_back( m_candidates[i] );
					dfs(now, cur-m_candidates[i], i+1);
					cur -= m_candidates[i];
				}
				if (cur == 0)
				{
					ret.push_back( now );
				}
				while (cur < remain)
				{
					now.pop_back();
					cur += m_candidates[i];
				}				
			}
		}
	}
};