// Copyright 2014 Qi Wang
// Date: 2014-07
class Solution 
{
public:
    int searchInsert(int A[], int n, int target) 
    {
    	int l=0, r=n-1, mid;
    	while (l <= r)
    	{
    		mid = (l+r) >> 1;
    		if (A[mid] == target)
    		{
    			return mid;
    		} else if (A[mid]<target && (mid+1==n || A[mid+1]>target)) // 边界检查
    		{
    			return mid+1;
    		} else if (A[mid] < target)
    		{
    			l = mid + 1;
    		} else
    		{
    			r = mid - 1;
    		}
    	}    
    }
};
