#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int> &num) 
    {
        vector<vector<int> > ret;

        sort (num.begin(), num.end());
        for (size_t a = 0; a < num.size(); ++ a)
        {
            if (a!=0 && num[a] == num[a-1])
            { 
                continue;
            }
            size_t b=a+1, c=num.size()-1;
            while (b < c)
            {
                if (0 > num[a]+num[b]+num[c])
                {
                    ++ b;
                } else if (0 < num[a]+num[b]+num[c])
                {
                    -- c;
                } else if (b!=a+1 && num[b]==num[b-1])
                {
                    ++ b;
                } else if (c!=num.size()-1 && num[c]==num[c+1])
                {
                    -- c;
                } else 
                {
                    vector<int> item;
                    item.push_back(num[a]);
                    item.push_back(num[b]);
                    item.push_back(num[c]);
                    ret.push_back(item);
                    ++ b;
                    -- c;
                }
            }
        }

        return ret;
    }
};

// old 
class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int> &num) 
    {
        if (num.empty() == true)
        {
            return vector<vector<int> >();
        }
        
    	vector<vector<int> > ret;

    	sort(num.begin(), num.end());
    	for (int i = 0; i < int(num.size())-2; ++ i)
    	{
			if (i!=0 && num[i]==num[i-1])
			{
				continue;
			}
    		for (int j = i+1; j < int(num.size())-1; ++ j)
    		{
    			if (j!=i+1 && num[j]==num[j-1])
    			{
    				continue;
    			}
    			if ( binary_search(num, 0-num[i]-num[j], j+1) )
    			{
    				vector<int> item;
    				item.push_back(num[i]);
    				item.push_back(num[j]);
    				item.push_back(0-num[i]-num[j]);
    				ret.push_back(item);
    			}
    		}
    	}   

    	return ret; 
    }
private:
	bool binary_search(vector<int>& num, int target, int l)
	{
		int r = num.size()-1;
		while (l <= r)
		{
			int mid = (l+r)/2;
			if (num[mid] < target)
			{
				l = mid + 1;
			} else if (num[mid] > target)
			{
				r = mid - 1;
			} else
			{
				return true;
			}
		}
		return false;
	}
};