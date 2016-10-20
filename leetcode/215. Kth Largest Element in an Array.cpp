class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int begin = 0, end = nums.size() - 1;

        while (begin < end)
        {
        	int left = begin, right = end;
        	int pivot = nums[left];
        	while (left < right)
        	{
    	    	for (; left < right && nums[right] < pivot; -- right) {}
    	    	nums[left] = nums[right];        		
	        	for (; left < right && nums[left] >= pivot; ++ left) {}
	        	nums[right] = nums[left];
        	}
        	nums[left] = pivot;
        	if (left == k - 1)
        	{
        		return nums[left];
        	} else if (left > k - 1)
        	{
        		end = left - 1;
        	} else 
        	{
        		begin = left + 1;
        	}
        }

        return nums[k-1];
    }
};