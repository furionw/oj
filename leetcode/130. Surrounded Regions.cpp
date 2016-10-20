struct Position
{
	Position(int x, int y) : x(x), y(y) {}
	int x, y;
};

class Solution 
{
public:
    void solve(vector<vector<char>> &board) 
    {
    	if (board.size()==0 || board[0].size()==0)
    	{
    		return ;
    	}

    	int n = board.size();
    	int m = board[0].size();
    	vector<vector<bool>> vi(board.size(), vector<bool>(board[0].size(), false));
		stack<Position> s;
    	for (int i = 0; i < n; ++ i)
    	{
			s.push(Position(i, 0));
			s.push(Position(i, m - 1));
    	}
    	for (int j = 0; j < m; ++ j)
    	{
			s.push(Position(0, j));
			s.push(Position(n - 1, j));
    	}
    	while (s.empty() == false)
    	{
			Position p = s.top();
    		s.pop();
    		if (p.x>=0 && p.x<n && p.y>=0 && p.y<m)
    		{
    			if (vi[p.x][p.y]==false && board[p.x][p.y]=='O')
    			{
    				vi[p.x][p.y] = true;
    				board[p.x][p.y] = 'Z';
					s.push(Position(p.x - 1, p.y));
					s.push(Position(p.x + 1, p.y));
					s.push(Position(p.x, p.y - 1));
					s.push(Position(p.x, p.y + 1));
    			}
    		}
    	}

    	for (int i = 0; i < n; ++ i)
    	{
    		for (int j = 0; j < m; ++ j)
    		{
    			board[i][j] = (board[i][j]=='Z')? 'O': 'X';
    		}
    	}
    }
};