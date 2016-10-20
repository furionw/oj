class Solution 
{
public:
    string minWindow(string S, string T) 
    {
    	int has_found[256] = {0};
    	int need_find[256] = {0};
    	size_t min_length = INT_MAX;
    	size_t min_begin = 0;

    	for (size_t i = 0; i < T.size(); ++ i)
    	{
    		++ need_find[T[i]];
    	}
    	for (size_t cnt = T.size(), begin=0, end=0; end < S.size(); ++ end)
    	{
    		++ has_found[S[end]];
    		if (has_found[S[end]] <= need_find[S[end]])
    		{
    			-- cnt;
    		}
    		if (cnt == 0)
    		{
    			for ( ; has_found[S[begin]] > need_find[S[begin]]; ++ begin)
    			{
    				-- has_found[S[begin]];
    			}
    			if (end-begin+1 < min_length)
    			{
    				min_length = end-begin+1;
    				min_begin = begin;
    			}
    		}
    	}

    	return min_length==INT_MAX? "": S.substr(min_begin, min_length);
    }
};