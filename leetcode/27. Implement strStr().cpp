// second time
class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        // pre_process, O(M) time complexity
        int next[needle.size()];
        next[0] = 0;
        for (size_t i = 1; i < needle.size(); ++ i)
        {
            int length = next[i-1];
            for (; length!=0 && needle[length]!=needle[i]; length = next[length-1]) {}
            next[i] = length + (needle[i]==needle[length]? 1: 0);
        }
        // match, O(N) time complexity
        size_t i = 0, j = 0;
        while (i < haystack.size() && j < needle.size())
        {
            for (; j!=0 && haystack[i]!=needle[j]; j = next[j-1]) {}
            j = j + (haystack[i++]==needle[j]? 1: 0);
        }
        return j==needle.size()? i-needle.size(): -1;
    }
};

// first time
class Solution 
{
public:
    char *strStr(char *haystack, char *needle) 
    {
    	for (int i = 0; i < int(strlen(haystack))-int(strlen(needle))+1; ++ i)
    	{
    		int j = 0;
    		for ( ; j < strlen(needle); ++ j)
    		{
    			if (*(haystack+i+j) != *(needle+j))
    			{
    				break;
    			}
    		}
    		if (j == strlen(needle))
    		{
    			return haystack+i;
    		}
    	}    
    	return NULL;
    }
};

