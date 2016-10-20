class Solution 
{
public:
    vector<int> searchRange(int A[], int n, int target) 
    {
    	vector<int> ret(2, -1);

    	int l=0, r=n-1, mid;
    	while (l <= r)
    	{
    		mid = (l+r) >> 1;
    		if (A[mid] == target)
    		{
    			break;
    		} else if (A[mid] < target)
    		{	
    			l = mid + 1;
    		} else
    		{
    			r = mid - 1;
    		}
    	}
    	if (A[mid] == target)
    	{
	    	for (ret[0]=mid; ret[0]-1>=0 && A[ret[0]-1]==target; -- ret[0]) {}
	    	for (ret[1]=mid; ret[1]+1< n && A[ret[1]+1]==target; ++ ret[1]) {}
		}

		return ret;
    }
};