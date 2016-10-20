class Solution
{
public:  
    int maximalRectangle(vector<vector<char> > &matrix) 
    {
    	if (matrix.empty() == true)
    	{
    		return 0;
    	}

    	size_t n=matrix.size(), m=matrix[0].size();
    	vector<vector<int>> cnt(n, vector<int>(m));
    	int maxx = 0;

    	for (size_t j = 0; j < m; ++ j)
    	{	
    		for (size_t i = 0; i < n; ++ i)
    		{
				if (i == 0)
				{
					cnt[i][j] = matrix[i][j] - '0';
				} else
				{
	    			cnt[i][j] = matrix[i][j]=='0'? 0: 1+cnt[i-1][j];
				}
    		}
    	}
    	for (size_t i = 0; i < n; ++ i)
    	{
    		maxx = max(maxx, largestRectangleArea(cnt[i]));
    	}

    	return maxx;
    }

private:
    int largestRectangleArea(vector<int> &height) 
    {
        height.push_back(-1); // dummy element
        stack<int> s;
        int maxx = 0;

        for (int i = 0; i < height.size(); )
        {
            if (s.empty()==true || height[s.top()]<=height[i])
            {
                s.push(i ++); // -1 will be pushed at last, and nothing will happen
            } else 
            {
                int top_index = s.top();
                s.pop();
                maxx = max(maxx, height[top_index]*(s.empty()? i: i-s.top()-1));
            }
        }

        return maxx;
    }	
};