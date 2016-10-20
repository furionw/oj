class Solution 
{
public:
    void merge(int A[], int m, int B[], int n) 
    {
    	int i=0, j=0, index=m;
    	vector<int> vt(m+n, 0);
    	while ( i<m && j<n )
    	{
    		if (A[i] < B[j])
    		{
    			vt[index ++] = A[i ++];
    		} else
    		{
    			vt[index ++] = B[j ++];
    		}
    	}
    	for ( ; i < m; vt[index ++] = A[i ++]) {}
    	for ( ; j < n; vt[index ++] = B[j ++]) {}
    	for (i = 0; i < n+m; ++ i)
    	{
    		A[i] = vt[i];
    	}
    }
};