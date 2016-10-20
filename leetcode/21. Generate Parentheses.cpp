class Solution 
{
public:
    vector<string> generateParenthesis(int n) 
    {
    	vector<string> ret;
        gao(0, 2*n, 0, 0, string(), ret);
        return ret;
    }
private:
	void gao(int dep, int max_dep, int left_now, int left_tot, string s, vector<string>& ret)
	{
		if (left_tot*2 > max_dep)
		{
			return ;
		} else if (dep == max_dep)
		{
			ret.push_back(s);
			return ;
		}

		gao(dep+1, max_dep, left_now+1, left_tot+1, s+'(', ret);
		if (left_now > 0)
		{
			gao(dep+1, max_dep, left_now-1, left_tot, s+')', ret);
		}
	}
};