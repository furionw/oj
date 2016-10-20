#include <vector>
#include <queue>

using namespace std;

class Solution 
{
public:
    int minPathSum(vector<vector<int> > &grid) 
    {
        if (grid.size() == 0)
        {
            return 0;
        }        
        // trick, 变成(n+1)*(m+1)矩阵, 避免了边界的初始化问题.
        vector<vector<int>> sum(grid.size()+1, vector<int>(grid[0].size()+1, INT_MAX));
        for (int i = 1; i < sum.size(); ++ i)
        {
            for (int j = 1; j < sum[0].size(); ++ j)
            {
                if (i==1 && j==1) 
                {
                    sum[1][1] = grid[0][0];
                } else
                {
                    sum[i][j] = min(sum[i-1][j], sum[i][j-1]) + grid[i-1][j-1];
                }
            }
        }
        return sum[sum.size()-1][sum[0].size()-1];
    }
};

/*

struct Item
{
	Item(int _d, int _i, int _j): dis(_d), i(_i), j(_j) {}
	int dis;
	int i;
	int j;
};

struct cmp
{
	bool operator () (const Item& a, const Item& b)
	{
		return a.dis > b.dis;
	}
};

class Solution 
{
public:
    int minPathSum(vector<vector<int> > &grid) 
    {
    	vector<vector<bool>> vi;
    	vector<vector<int>> dis;
		priority_queue<Item, vector<Item>, cmp> q;
    	for (int i = 0; i < grid.size(); ++ i)
    	{
    		vi.push_back(vector<bool>(grid[0].size(), false));
    		dis.push_back(vector<int>(grid[0].size(), INT_MAX));
    	}
//    	vi[0][0] = true;
    	dis[0][0] = grid[0][0];
		q.push(Item(grid[0][0], 0, 0));

    	for (int k = 0; k < grid.size()*grid[0].size(); ++ k)
    	{
    		int i = 0, j = 0, minn = INT_MAX;
			while(q.empty()==false && vi[q.top().i][q.top().j]==true)
			{
				q.pop();
			}

			if (q.empty()==true)
			{
				break;
			} else
			{
				i = q.top().i;
				j = q.top().j;
				q.pop();
			}
    		vi[i][j] = true;

    		if (i>0 && dis[i-1][j]>dis[i][j]+grid[i-1][j])
    		{
    			dis[i-1][j] = dis[i][j] + grid[i-1][j];
				q.push(Item(dis[i-1][j], i-1, j));
    		}
    		if (i<grid.size()-1 && dis[i+1][j]>dis[i][j]+grid[i+1][j])
    		{
    			dis[i+1][j] = dis[i][j] + grid[i+1][j];
                q.push(Item(dis[i+1][j], i+1, j));
    		}
    		if (j>0 && dis[i][j-1]>dis[i][j]+grid[i][j-1])
    		{
    			dis[i][j-1] = dis[i][j] + grid[i][j-1];
                q.push(Item(dis[i][j-1], i, j-1));
    		}
    		if (j<grid[0].size()-1 && dis[i][j+1]>dis[i][j]+grid[i][j+1])
    		{
    			dis[i][j+1] = dis[i][j] + grid[i][j+1];
                q.push(Item(dis[i][j+1], i, j+1));
    		}
    	}

    	return dis[grid.size()-1][grid[0].size()-1];
    }
};