class Solution 
{
public:
    int climbStairs(int n) 
    {
    	int prev=1, prevv=1, ret=1;
    	for (int i = 2; i <= n; ++ i)
    	{
    		ret = prev + prevv;
    		prevv = prev;
    		prev = ret;
    	}
    	return ret;
    }
};