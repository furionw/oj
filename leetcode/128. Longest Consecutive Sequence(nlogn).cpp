class Solution 
{
public:
    int longestConsecutive(vector<int> &num) 
    {
    	if (num.size() == 0)
    	{
    		return 0;
    	}

        int ret = 1, tmp = 1;
    	sort(num.begin(), num.end());
        for (size_t i = 1; i < num.size(); ++ i)
        {
            if (num[i] == num[i-1] + 1)
            {
                ++ tmp;
                ret = max(ret, tmp);
            } else if (num[i] != num[i-1])
            {
                tmp = 1;
            }
        }
        return ret;
    }
};