class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
		vector<vector<int>> vt;

		for (int i = 0; i < m; ++ i)
		{
			vector<int> line(n, 0);
			vt.push_back(line);
		}
		for (int i = 0; i < n; ++ i)
		{
			vt[0][i] = 1;
		}
		for (int i = 1; i < m; ++ i)
		{
			vt[i][0] = 1;
		}
		for (int i = 1; i < m; ++ i)
		{
			for (int j = 1; j < n; ++ j)
			{
				vt[i][j] = vt[i-1][j] + vt[i][j-1];
			}
		}

		return vt[m-1][n-1];
	}
};