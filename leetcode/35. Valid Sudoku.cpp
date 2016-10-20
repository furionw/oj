class Solution 
{
public:
    bool isValidSudoku(vector<vector<char> > &board) 
    {
        vector<int> cnt(9, 0);

        for (int i = 0; i < 9; ++ i)
        {
			cnt.assign(9, 0);
        	for (int j = 0; j < 9; ++ j)
        	{
        		if (board[i][j] == '.')
        		{
        			continue;
        		} else if ( ++ cnt[board[i][j] - '1'] > 1)
        		{
        			return false;
        		}
        	}
        }
        for (int j = 0; j < 9; ++ j)
        {
        	cnt.assign(9, 0);
        	for (int i = 0; i < 9; ++ i)
        	{
        		if (board[i][j] == '.')
        		{
        			continue;
        		} else if ( ++ cnt[board[i][j] - '1'] > 1)
        		{
        			return false;
        		}
        	}
        }
        return square_judge(0, 0, board) && square_judge(0, 3, board) && square_judge(0, 6, board)
        && square_judge(3, 0, board) && square_judge(3, 3, board) && square_judge(3, 6, board)
        && square_judge(6, 0, board) && square_judge(6, 3, board) && square_judge(6, 6, board);
    }
private:
	bool square_judge(int x, int y, const vector<vector<char> > &board)
	{
		vector<int> cnt(9, 0);
		for (int i = 0; i < 3; ++ i)
		{
			for (int j = 0; j < 3; ++ j)
			{
        		if (board[x+i][y+j] == '.')
        		{
        			continue;
        		} else if ( ++ cnt[board[x+i][y+j] - '1'] > 1)
        		{
        			return false;
        		}				
			}
		}
		return true;
	}
};
