#include <vector>

using namespace std;

// second time
class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
    	if (grid.size() == 0)
    	{
    		return 0;
    	}

    	int cnt = 0;    	
		int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
		vector<vector<bool>> vi(grid.size(), vector<bool>(grid[0].size(), false));

    	for (int i = 0; i < grid.size(); ++ i)
    	{
    		for (int j = 0; j < grid[0].size(); ++ j)
    		{
    			if (grid[i][j] == '1' && vi[i][j] == false)
    			{
    				++ cnt;
    				dfs(i, j, grid, vi, dir);
    			}
    		}
    	}

    	return cnt;
    }

private:
	void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& vi, int dir[][2])
	{
		vi[x][y] = true;
		for (int i = 0; i < 4; ++ i)
		{
			int new_x = x+dir[i][0], new_y = y+dir[i][1];
			if (new_x>=0 && new_x<grid.size() && new_y>=0 && new_y<grid[0].size()
				&& grid[new_x][new_y]=='1' && vi[new_x][new_y]==false)
			{
					dfs(new_x, new_y, grid, vi, dir);
			}
		}
	}
};

// first time
class Solution 
{
public:
    int numIslands(vector<vector<char>> &grid) 
    {
    	if (grid.size() == 0)
    	{
    		return 0;
    	}

    	int cnt = 0;
    	vector<vector<bool>> vi(grid.size(), vector<bool>(grid[0].size(), false));   

    	for (size_t i = 0; i < grid.size(); ++ i)
    	{
    		for (size_t j = 0; j < grid[0].size(); ++ j)
    		{
    			if (grid[i][j] == '1' && vi[i][j] == false)
    			{
    				++ cnt;
    				bfs(static_cast<int>(i), static_cast<int>(j), grid, vi);
    			}
    		}
    	}

    	return cnt;
    }
private:
	void bfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& vi)
	{
		vi[x][y] = true;

		int offset[] = {-1, 0, 1};
		for (int i = 0; i < 3; ++ i)
		{
			for (int j = 0; j < 3; ++ j)
			{
				// offset constrains
				if (i == j || i+j == 2)
				{
					continue;
				}
				int xx = x+offset[i], yy = y+offset[j];
				if (xx >= 0 && xx < grid.size()
					&& yy >=0 && yy < grid[0].size())
				{
					if (grid[xx][yy] == '1' && vi[xx][yy] == false)
					{
						vi[xx][yy] = true;
						bfs(xx, yy, grid, vi);
					}
				}
			}
		}
	}
};