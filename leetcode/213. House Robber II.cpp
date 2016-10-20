class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
    	if (nums.empty())
    	{
    		return 0;
    	} else if (nums.size() == 1)
    	{
    		return nums[0];
    	} else if (nums.size() == 2)
    	{
    		return max(nums[0], nums[1]);
    	}

    	// i: nums index, j: self taken or not, k: nums[0] taken or not
    	vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(2, vector<int>(2, 0)));
    	// for stage-0
    	dp[0][1][1] = nums[0];
    	// for stage-1
    	dp[1][0][1] = nums[0];
    	dp[1][1][0] = nums[1];
    	for (size_t i = 2; i < nums.size(); ++ i)
    	{
    		dp[i][0][0] = max(dp[i-1][0][0], dp[i-1][1][0]);
    		dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][1][1]);
    		dp[i][1][0] = dp[i-1][0][0] + nums[i];
    		dp[i][1][1] = dp[i-1][0][1] + nums[i];
    	}

    	return max(max(dp[nums.size()-1][0][0], dp[nums.size()-1][0][1]), 
    		dp[nums.size()-1][1][0]);
    }
};