class Solution 
{
public:
    int jump(int A[], int n) 
    {
    	int step = 0;

    	for (int i=0, bound=0, next=0; next < n - 1; ++ step)
    	{
        	for ( ; i <= bound; ++ i)
        	{
        		next = max(next, i+A[i]);
        	}
        	bound = next;
    	}

    	return step;
    }
};