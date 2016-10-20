#include <vector>

using namespace std;

class Solution 
{
public:
    int threeSumClosest(vector<int> &num, int target) 
    {
    	int closest = INT_MAX, ret;

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
    			int ans = binary_search(num, target-num[i]-num[j], j+1) ;
    			if (closest > abs(target-num[i]-num[j]-ans))
                {
                    closest = abs(target-num[i]-num[j]-ans);
                    ret = num[i] + num[j] + ans;
                }
    		}
    	}   

    	return ret; 
    }
private:
	int binary_search(vector<int>& num, int target, int l)
	{
		int r = num.size()-1, mid;
		while (l <= r)
		{
			mid = (l+r)/2;
			if (num[mid] < target)
			{
                if (abs(target-num[mid]) >= abs(target-num[mid+1]))
                {
    				l = mid + 1;
                } else
                {
                    break;
                }
			} else if (num[mid] > target)
			{
                if (abs(target-num[mid]) >= abs(target-num[mid-1]))
                {
    				r = mid - 1;
                } else
                {
                    break;
                }
			} else
			{
				break;
			}
		}
        return num[mid];
	}
};