#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
	bool exist(vector<vector<char> > &board, string word) 
	{
		if (board.empty()==true || word.empty()==true)
		{
			return false;
		}
		size_t n=board.size(), m=board[0].size();    	
		auto vi = vector<vector<bool>>(n, vector<bool>(m, false));
		for (int i = 0; i < n; ++ i)
		{
			for (int j = 0; j < m; ++ j)
			{
				if (board[i][j] == word[0])
				{
					if (gao(vi, board, i, j, 1, word))
					{
						return true;
					}
				}
			}
		}
		return false;
	}
private:
	bool gao(vector<vector<bool>>& vi, vector<vector<char>>& board,
		int x, int y, size_t cnt, string& word)
	{
		vi[x][y] = true;
		int x_dir[] = {-1, 0, 1, 0};
		int y_dir[] = {0, 1, 0, -1};
		if (cnt == word.size())
		{
			return true;
		}
		for (int i = 0; i < 4; ++ i)
		{
			int x_next = x + x_dir[i];
			int y_next = y + y_dir[i];
			if( x_next>=0 && x_next<board.size()
				&& y_next>=0 && y_next<board[0].size()
				&& board[x_next][y_next]==word[cnt]
				&& vi[x_next][y_next]==false
				&& gao(vi, board, x_next, y_next, cnt+1, word) )
			{
				return true;	
			}
		}
		vi[x][y] = false;
		return false;
	}
//	int x_dir[] = {-1, 0, 1, 0};
//	int y_dir[] = {0, 1, 0, -1};
};