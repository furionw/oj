class Solution 
{
public:
    string getPermutation(int n, int k) 
    {
    	int num[] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320};
    	bool vi[10] = {false, false};
    	string ret = string(n, 0);

    	for (int i = n-1; i > 0; -- i)
    	{
    		int cnt = 1, digit = 1;
    		for ( ; k - num[i] > 0; k-=num[i], ++cnt) {}
			for ( ; (cnt-1>0||vi[digit]==true) && digit<n; ++ digit)
			{
				if (vi[digit] == false)
				{
					-- cnt;
				}
			}    		
    		ret[n-1-i] = digit + '0';
    		vi[digit] = true;
    	}
    	for (int i = 1; i <= n; ++ i)
    	{
    		if (vi[i] == false)
    		{
    			ret[n-1] = i + '0';
    			break;
    		}
    	}

    	return ret;
    }
};