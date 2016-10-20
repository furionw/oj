#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
    	if (nums.empty())
    	{
    		return 0;
    	}

    	vector<int> sum(nums.size(), 0);
    	vector<int> len(nums.size(), 0);
    	sum[0] = nums[0];
    	len[0] = 1;
    	int min_len = sum[0]>=s? 1: INT_MAX;
    	int begin = 0;

    	for (size_t i = 1; i < nums.size(); ++ i)
    	{
 			sum[i] = sum[i-1] + nums[i];
    		if (sum[i] < s)
    		{
    			len[i] = len[i-1] + 1;
    		} else
    		{
    			// note that this 'begin' won't be larger than nums.size()
    			for (; sum[i] - nums[begin] >= s; sum[i] -= nums[begin], ++ begin) {}
    			len[i] = i - begin + 1;
    			min_len = min(min_len, len[i]);
    		}
    	}

    	return min_len==INT_MAX? 0: min_len;
    }
};

// int main() {}