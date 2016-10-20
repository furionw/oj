class Solution 
{
public:
    void solveSudoku(vector<vector<char> > &board) 
    {
		dfs(board);
    }
private:
	bool dfs(vector<vector<char> > &board)
	{
		for (int i = 0; i < 9; ++ i)
		{
			for (int j = 0; j < 9; ++ j)
			{
				if (board[i][j] != '.')
				{
					continue;
				} 
				for (int k = 1; k <= 9; ++ k)
				{
					board[i][j] = k+48;
					if (is_valid(board, i, j) && dfs(board))
					{
						return true;
					}
					board[i][j] = '.';
				}
				return false;
			}
		}
		return true;
	}
	bool is_valid(vector<vector<char> > &board, int x, int y)
	{
		for (int j = 0; j < 9; ++ j)
		{
			if ( j!=y && board[x][j]==board[x][y] )
			{
				return false;
			}
		}
		for (int i = 0; i < 9; ++ i)
		{
			if ( i!=x && board[i][y]==board[x][y] )
			{
				return false;
			}
		}
		for (int i = 3*(x/3); i < 3*(x/3)+3; ++ i)
		{
			for (int j = 3*(y/3); j < 3*(y/3)+3; ++ j)
			{
				if ( i!=x && j!=y && board[i][j]==board[x][y] )
				{
					return false;
				}
			}
		}
		return true;
	}
};