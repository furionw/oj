class Solution 
{
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) 
    {
    	if ((m+n) % 2 == 1)
    	{
    		return find_kth(A,m,B,n,(m+n)/2+1);
    	} else // even
    	{
    		return (find_kth(A,m,B,n,(m+n)/2)+find_kth(A,m,B,n,(m+n)/2+1)) / 2.0;
    	}
    }

private:
	int find_kth(int A[], int m, int B[], int n, int k)
	{
		if (m == 0)
		{
			return B[k-1];
		} else if (m > n) // maintain m < n
		{
			return find_kth(B, n, A, m, k);
		} else if (k == 1)
		{
			return min(A[0], B[0]);
		}
		int pa = min(k/2, m), pb = k-pa;
		if (A[pa-1] < B[pb-1])
		{
			return find_kth(A+pa, m-pa, B, n, k-pa); // maintain pointers and k-th here
		} else if (A[pa-1] > B[pb-1])
		{
			return find_kth(A, m, B+pb, n-pb, k-pb); // maintain pointers and k-th here
		} else
		{
			return A[pa-1];
		}
	}
};