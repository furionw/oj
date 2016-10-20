class Solution 
{
public:
    int longestConsecutive(vector<int> &num) 
    {
    	if (num.size() == 0)
    	{
    		return 0;
    	}

    	int ret = 1;
    	int cnt = 1;
    	int prev = -1;
    	priority_queue<int> q;

    	for (size_t i = 0; i < num.size(); ++ i)
    	{
    		q.push( num[i] );
    	}
    	while (q.empty() == false)
    	{
    		int top = q.top();
    		if (top + 1 == prev)
    		{
    			++ cnt;
    		} else if (top == prev)
    		{
    			// do nothing
    		} else
    		{
    			cnt = 1;
    		}
  			prev = top;    		
    		ret = max(ret, cnt);
    		q.pop();
    	}

    	return ret;
    }
};