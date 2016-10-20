class Solution
{
public:
	vector<int> grayCode(int n)
	{
		vector<int> ret;
		for (int i=0, num=1<<n; i < num; ++ i)
		{
			ret.push_back( (i>>1)^i );
		}
		return ret;
	}
};