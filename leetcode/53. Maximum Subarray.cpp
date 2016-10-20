class Solution 
{
public:
    int maxSubArray(int A[], int n) 
    {
    	int cur=0, maxx=INT_MIN;

    	for (int i = 0; i < n; ++ i)
    	{
    		cur += A[i];
    		maxx = max(maxx, cur);
    		cur = max(cur, 0);
    	}   

    	return maxx;
    }
};