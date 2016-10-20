class Solution 
{
public:
    string convertToTitle(int n) 
    {
    	string ret;
    	while (n != 0)
    	{
    		ret.insert(ret.begin(), 'A' + (n-1)%26);
    		n = (n-1) / 26;
    	}    
    	return ret;
    }
};