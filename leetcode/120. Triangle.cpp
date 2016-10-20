#include <algorithm>
#include <vector>

using namespace std;

class Solution 
{
public:
    int minimumTotal(vector<vector<int> > &triangle) 
    {
    	auto dp = triangle;
		
		// dp initilization in the first loop
    	for (int j = 0; j < dp.back().size(); ++ j)	
    	{
    		dp.back()[j] = triangle.back()[j];	
    	}
    	for (int i = int(dp.size())-2; i >= 0; -- i)
    	{
    		for (int j = 0; j < dp[i].size(); ++ j)
    		{
    			dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
    		}
    	}

    	return dp[0][0];
    }
};

class Solution 
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        return gao(triangle, 0, 0);
    }
private:
    int gao(vector<vector<int>> &triangle, int x, int y)
    {
        if (x == triangle.size())
        {
            return 0;
        } else
        {
            return triangle[x][y] + min(gao(triangle, x+1, y), gao(triangle, x+1, y+1));
        }
    }
};

/*
int main()
{
	vector<vector<int>> triangle(2, vector<int>());
	triangle.front().push_back(1);
	triangle.back().push_back(2);
	triangle.back().push_back(3);

	Solution a;
	a.minimumTotal( triangle );

	return 0;
}*/