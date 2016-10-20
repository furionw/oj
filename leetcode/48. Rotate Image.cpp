class Solution 
{
public:
    void rotate(vector<vector<int> > &matrix) 
    {
    	// 要用int, 否则matrix.size()==2时，-- bottom_right溢出
        for (int top_left=0, bottom_right=matrix.size()-1; top_left < bottom_right; 
        	++ top_left, -- bottom_right)
        {
        	for (size_t i = 0; i < bottom_right - top_left; ++ i)
        	{
        		swap(matrix[top_left][top_left+i], matrix[top_left+i][bottom_right]);
        		swap(matrix[top_left][top_left+i], matrix[bottom_right-i][top_left]);
        		swap(matrix[bottom_right-i][top_left], matrix[bottom_right][bottom_right-i]);
        	}
        }
    }
};


/*
        for (int i = 0; i < (n+1)/2; ++ i)
        {
        	for (int j = i; j < (n+1)/2; ++ j)
        	{
        		swap(matrix[i][j], matrix[j][n-i-1]);
        		swap(matrix[i][j], matrix[n-j-1][i]);
        		swap(matrix[n-j-1][i], matrix[n-i-1][n-j-1]);
        	}
        }
        for (int i = 1; i < n/2; ++ i)
        {
        	for (int j = 0; j < i; ++ j)
        	{
        		swap(matrix[i][j], matrix[j][n-i-1]);
        		swap(matrix[i][j], matrix[n-j-1][i]);
        		swap(matrix[n-j-1][i], matrix[n-i-1][n-j-1]);
        	}
        }
*/