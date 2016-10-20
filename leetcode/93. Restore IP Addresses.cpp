class Solution 
{
public:
    vector<string> restoreIpAddresses(string s) 
    {
    	vector<string> now;
    	gao(now, 0, s, 0);
    	return ret;
    }
private:
	void gao(vector<string>& now, int depth, const string& s, int index)
	{	
		if ( int(s.size())-index > (4-depth)*3 )
		{
			return ;
		}

		if (now.size()==4 && index==s.size() && depth==4)
		{
			string addr;
			for (size_t i = 0; i < 4; ++ i)
			{
				addr += now[i];
			}
			ret.push_back(addr);
			return ;
		}
		if (index<s.size() && s[index]=='0')
		{
			now.push_back( (depth==0? string(""): string(".")) + s.substr(index, 1) );
			gao(now, depth+1, s, index+1);
			now.pop_back();
			return ;
		}
		for (int i = 1; i<=3 && index+i<=s.size(); ++ i)
		{
			if ( string_to_int(s.substr(index, i)) <= 255 )
			{
				now.push_back( (depth==0? string(""): string(".")) + s.substr(index, i) );
				gao(now, depth+1, s, index+i);
				now.pop_back();
			}	
		}
	}

	int string_to_int(const string& s)
	{
		int ret;
		stringstream ss;
		ss << s;
		ss >> ret;
		return ret;
	}
	vector<string> ret;
};