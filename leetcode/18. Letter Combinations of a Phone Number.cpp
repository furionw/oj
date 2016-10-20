class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
    	vector<string> ret(1, "");
    	string letters[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    	for (size_t i = 0; i < digits.size(); ++ i)
    	{
    		string str = letters[digits[i]-'2'];
    		for (int j = ret.size()-1; j >= 0; -- j)
    		{
    			for (int k = str.size()-1; k >= 0; -- k)
    			{
    				if (k != 0)
    				{
    					ret.push_back( ret[j] + str[k] );
    				} else
    				{
    					ret[j] += str[k];
    				}
    			}
    		}
    	}

    	return ret;
    }
};