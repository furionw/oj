class Solution 
{
public:
    int nthUglyNumber(int n) 
    {
        vector<int> nums(n, 1);
        int idx2 = 0; 
        int idx3 = 0;
        int idx5 = 0;
        
        for (int i = 1; i < n; ++ i)
        {
        	nums[i] = min(2*nums[idx2], min(3*nums[idx3], 5*nums[idx5]));        	
        	for (; 2 * nums[idx2] <= nums[i]; ++ idx2) {}
        	for (; 3 * nums[idx3] <= nums[i]; ++ idx3) {}
        	for (; 5 * nums[idx5] <= nums[i]; ++ idx5) {}
        }
        
    	return nums[n-1];
    }
};