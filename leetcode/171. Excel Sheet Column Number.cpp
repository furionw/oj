class Solution 
{
public:
    int titleToNumber(string s) 
    {
        int ret = 0;
        for (size_t i = 0; i < s.size(); ++ i)
        {
        	ret *= 26;
        	ret += (s[i] - 'A' + 1);
        }
        return ret;
    }
};