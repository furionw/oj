/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) 
{
    var hash = {};
    for (var i in nums)
    {
    	var index = hash[nums[i]];
    	for (var j in index)
    	{
    		if (Math.abs(i - index[j]) <= k)
    		{
    			return true;
    		}
    	}
    	hash[nums[i]] = [i].concat(hash[nums[i]]);
    }
    return false;
};


