class Solution 
{
public:
    int trap(int A[], int n) 
    {
    	int sum = 0;
		vector<int> leftmost(n, 0), rightmost(n, 0);

		for (int i = 0, maxx = 0; i < n; ++ i)
		{
			leftmost[i] = maxx;
			maxx = maxx>A[i]? maxx: A[i];
		}
		for (int i = n-1, maxx = 0; i >= 0; -- i)
		{
			rightmost[i] = maxx;
			maxx = maxx>A[i]? maxx: A[i];
		}
		for (int i = 1; i < n-1; ++ i)
		{
			if (min(leftmost[i], rightmost[i]) > A[i])
			{
				sum += min(leftmost[i], rightmost[i]) - A[i];
			}
		}

		return sum;
    }
};