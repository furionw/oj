class Solution 
{
public:
    int romanToInt(string s) 
    {
    	int ret = 0;
    	map<char, int> roman_to_int;
    	roman_to_int['M'] = 1000;
    	roman_to_int['D'] = 500;
    	roman_to_int['C'] = 100;
    	roman_to_int['L'] = 50;
    	roman_to_int['X'] = 10;
    	roman_to_int['V'] = 5;
    	roman_to_int['I'] = 1;

    	for (size_t i = 0; i < s.size(); ++ i)
    	{
    		if (i < s.size()-1 && roman_to_int[s[i]] < roman_to_int[s[i+1]])
    		{
    			ret = ret - roman_to_int[s[i]] + roman_to_int[s[i+1]];
    			++ i;
    		} else
    		{
    			ret = ret + roman_to_int[s[i]];
    		}
    	}

    	return ret;
    }
};