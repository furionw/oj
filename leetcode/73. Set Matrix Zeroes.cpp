class Solution 
{
public:
    void setZeroes(vector<vector<int> > &matrix) 
    {
    	bool first_row=false, first_column=false;
    	size_t n=matrix.size(), m=matrix[0].size();

    	for (size_t j = 0; j < m; ++ j)
    	{
    		if (matrix[0][j] == 0)
    		{
    			first_row = true;
    		}
    	}    
    	for (size_t i = 0; i < n; ++ i)
    	{
    		if (matrix[i][0] == 0)
    		{
    			first_column = true;
    		}
    	}
    	for (size_t i = 1; i < n; ++ i)
    	{
    		for (size_t j = 1; j < m; ++ j)
    		{
    			if (matrix[i][j] == 0)
    			{
    				matrix[0][j] = 0;
    				matrix[i][0] = 0;
    			}
    		}
    	}
    	for (size_t j = 1; j < m; ++ j)
    	{
    		if (matrix[0][j] == 0)
    		{
    			for (size_t i = 1; i < n; ++ i)
    			{
    				matrix[i][j] = 0;
    			}
    		}
    	}
    	for (size_t i = 1; i < n; ++ i)
    	{
    		if (matrix[i][0] == 0)
    		{
    			for (size_t j = 1; j < m; ++ j)
    			{
    				matrix[i][j] = 0;
    			}
    		}
    	}
    	if (first_row == true)
    	{
    		for (size_t j = 0; j < m; ++ j)
    		{
    			matrix[0][j] = 0;
    		}
    	}
    	if (first_column == true)
    	{
    		for (size_t i = 0; i < n; ++ i)
    		{
    			matrix[i][0] = 0;
    		}
    	}
    }
};