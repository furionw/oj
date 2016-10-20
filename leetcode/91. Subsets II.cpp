class Solution 
{
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) 
    {
    	if (S.empty())
    	{
    		return vector<vector<int>>();
    	}

    	sort(S.begin(), S.end());
    	num.push_back(S.front());
    	cnt.push_back(1);
    	for (size_t i = 1; i < S.size(); ++ i)
    	{
    		if (S[i] != S[i-1])
    		{
    			num.push_back(S[i]);
    			cnt.push_back(1);
    		} else
    		{
    			++ cnt.back();
    		}
    	}
    	vector<int> now;
    	for (size_t i = 0; i <= S.size(); ++ i)
    	{
    		gao(now, 0, i);
    	}

    	return ret;
    }
private:
	vector<int> num;
	vector<int> cnt;
	vector<vector<int>> ret;
	void gao(vector<int>& now, size_t index, size_t bound)
	{
		if (now.size() == bound)
		{
			ret.push_back(now);
			return ;
		}
		for (size_t i = index; i < num.size(); ++ i)
		{
			int j = 0;
			for (; j<cnt[i] && now.size()<bound; ++ j)
			{
				now.push_back(num[i]);
				gao(now, i+1, bound);
			}
			while (j --)
			{
				now.pop_back();
			}
		}
	}
};