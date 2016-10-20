class Solution 
{
public:
    int maxArea(vector<int> &height) 
    {
    	int maxx = 0, l = 0, r = height.size()-1;

    	while (l < r)
    	{
    		maxx = maxx>(r-l)*min(height[l], height[r])? maxx: (r-l)*min(height[l], height[r]);
    		if (height[l] < height[r])
    		{
    			++ l;
    		} else
    		{
    			-- r;
    		}
    	}

        return maxx;
    }
};