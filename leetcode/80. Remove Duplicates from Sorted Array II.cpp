class Solution 
{
public:
    int removeDuplicates(int A[], int n) 
    {
    	int length = 0;

    	for (int i=0; i < n; )
		{
			A[length ++] = A[i ++];
			if (i<n && A[i-1]==A[i])
			{
				A[length ++] = A[i ++];
			}
			for ( ; i<n && A[i]==A[i-1]; ++ i) {}
		}

		return length;
    }
};