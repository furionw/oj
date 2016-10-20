class Solution 
{
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) 
    {
    	vector<vector<int> > ret;

    	sort(num.begin(), num.end());
    	for (size_t a = 0; a<num.size(); ++ a)
    	{
    		if (a!=0 && num[a]==num[a-1])
    		{
    			continue;
    		}
    		for (size_t b=a+1; b<num.size(); ++ b)
    		{
    			if (b!=a+1 && num[b]==num[b-1])
    			{
    				continue;
    			}
    			size_t c = b+1, d = num.size()-1;
    			while (c < d)
    			{
    				if (target > num[a]+num[b]+num[c]+num[d])
    				{
    					++ c;
    				} else if (target < num[a]+num[b]+num[c]+num[d])
    				{
    					-- d;
    				} else if (c!=b+1 && num[c]==num[c-1])
    				{
    					++ c;
    				} else if (d!=num.size()-1 && num[d]==num[d+1])
    				{
    					-- d;
    				} else
    				{
    					vector<int> item;
    					item.push_back(num[a]);
    					item.push_back(num[b]);
    					item.push_back(num[c]);
    					item.push_back(num[d]);
    					ret.push_back(item);
    					++ c;
    					-- d;
    				}
    			}
    		}
    	}

    	return ret; 
    }
};