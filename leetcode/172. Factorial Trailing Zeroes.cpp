class Solution 
{
public:
    int trailingZeroes(int n) 
    {
    	int ret = 0, factor = 1;
    	for ( ; n / pow(5, factor) > 0; ++ factor)
    	{
    		ret += n / pow(5, factor);
    	}
    	return ret;
    }
};