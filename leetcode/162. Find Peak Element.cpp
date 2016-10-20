class Solution 
{
public:
    int findPeakElement(const vector<int> &num) 
    {
    	if (num.size() == 1)
    	{
    		return 0;
    	}
        for (int i = 0; i < num.size(); ++ i)
        {
        	if ((i - 1 >= 0 && i + 1 < num.size() && num[i] > num[i-1] && num[i] > num[i+1])
        		|| (i == 0 && i + 1 < num.size() && num[i] > num[i+1])
        		|| (i + 1 == num.size() && i - 1 >= 0 && num[i] > num[i-1]))
        	{
        		return i;
        	}
        }
        return INT_MAX;
    }
};