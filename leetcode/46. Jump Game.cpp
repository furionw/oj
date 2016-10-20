class Solution 
{
public:
    bool canJump(int A[], int n) 
    {
    	for (int i=0, bound=0; i <= bound; ++ i)
    	{
    		bound = max(A[i]+i, bound);
    		if (bound >= n-1)
    		{
    			return true;
    		}
    	}
    	return false;
    }
};