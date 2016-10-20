class Solution 
{
public:
    int lengthOfLastWord(const char *s) 
    {
    	bool find = false;
    	int ret = 0;

    	for (int i = strlen(s)-1; i >= 0; -- i)
    	{
    		if (s[i]==' ' && find==true)
    		{
    			return ret;
    		} else if (s[i] != ' ')
    		{
    			++ ret;
    			find = true;
    		}
    	}    

    	return ret;
    }
};