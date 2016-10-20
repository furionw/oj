class Solution 
{
public:
    bool isIsomorphic(string s, string t) 
    {
    	if (s.size() != t.size())
    	{
    		return false;
    	}

        for(size_t i = 0; i < s.size(); ++ i)
        {
        	if (dict[s[i]] == 0)
        	{
        		if (valid_mapping(s[i], t[i]))
        		{
        			dict[s[i]] = t[i];
        		} else
        		{
        			return false;
        		}
        	} else if (dict[s[i]] != t[i])
        	{
        		return false;
        	}
        }

        return true;
    }
    
private:
	bool valid_mapping(char from, char to)
	{
		for (auto it = dict.begin(); it != dict.end(); ++ it)
		{
			if (to == it->second)
			{
				return false;
			}
		}
		return true;
	}
	map<char, char> dict;
};