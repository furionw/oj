class Solution 
{
public:
    int firstMissingPositive(int A[], int n) 
    {
    	for (int i = 0; i < n; ++ i)
    	{
    		while (A[i]>0 && A[i]<=n && A[i]-1!=i && A[A[i]-1]!=A[i])
    		{
    			swap(A[i], A[A[i]-1]);
    		}
    	}
    	for (int i = 0; i < n; ++ i)
    	{
    		if (A[i]-1 != i )
    		{
    			return i + 1;
    		}
    	}
    	return n+1; 
    }
};