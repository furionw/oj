class Solution 
{
public:
    vector<vector<int> > generate(int numRows) 
    {
    	vector<vector<int>> ret(numRows, vector<int>());
    	
        for (int i = 0; i < numRows; ++ i)
        {
        	for (int j = i; j < numRows; ++ j)
        	{
        		if (i==0 || j==i)
        		{
        			ret[j].push_back(1);
        		} else
        		{
        			ret[j].push_back( ret[j-1][i-1] + ret[j-1][i] );
        		}
        	}
        }

        return ret;
    }
};