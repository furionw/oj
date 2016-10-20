class Solution 
{
public:
    int numDecodings(string s) 
    {
    	if ( s.empty() )
    	{
    		return 0;
    	} else if ( s[0] == '0' )
    	{
    		return 0;
    	} else if ( s.size() == 1)
    	{
    		return 1;
    	}

    	vector<int> dp(s.size(), 1);
    	if (s[1] == '0')
    	{
    		if (s[0]!='1' && s[0]!='2')
    		{
    			return 0;
    		} else
    		{
    			dp[1] = dp[0];
    		}
    	} else 
    	{
    		if (2<s.size() && s[2]=='0')
    		{
    			dp[1] = dp[0];
    		} else
    		{
				dp[1] = dp[0] + (string_to_int(s.substr(0, 2))<=26? 1: 0);    			
    		}
    	}
    	for (size_t i = 2; i < s.size(); ++ i)
    	{
    		if (s[i]=='0')
    		{
    			if (s[i-1]!='1' && s[i-1]!='2')
    			{
    				return 0;
    			} else
    			{
	    			dp[i] = dp[i-1];
	    		}
    		} else // 自身非0
    		{
    			if (s[i-1] == '0')
    			{
    				dp[i] = dp[i-1];
    			} else if (i+1<s.size() && s[i+1]=='0')
    			{
    				dp[i] = dp[i-1];
    			} else
	    		{
					dp[i] = dp[i-1] + (string_to_int(s.substr(i-1, 2))<=26? dp[i-2]: 0);    			
	    		}
	    	}
    	}

    	return dp.back();
    }
private:
	int string_to_int(const string& s)
	{
		int ret;
		stringstream ss;
		ss << s;
		ss >> ret;
		return ret;
	}
};