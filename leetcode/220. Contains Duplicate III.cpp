class Solution 
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        multiset<long long> bst;
        for (size_t i = 0; i < nums.size(); ++ i)
        {
        	if (bst.size() == k+1)
        	{
        		bst.erase(nums[i-k-1]);
        	}
        	auto lb = bst.lower_bound(nums[i]-t);        	
        	if (lb!=bst.end() && *lb-nums[i]<=t)
        	{
        		return true;
        	}
        	bst.insert(nums[i]);
        }
        return false;
    }
};