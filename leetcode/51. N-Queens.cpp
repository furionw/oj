class Solution 
{
public:
    vector<vector<string> > solveNQueens(int n) 
    {
        vector<int> vt(n, 0);
        vector<vector<string> > ret;

        gao(vt, 0, n);
        for (size_t i = 0; i < record.size(); ++ i)
        {
        	vector<string> board;
        	for (size_t j = 0; j < n; ++ j)
        	{
        		string line(n, '.');
        		line[record[i][j]] = 'Q';
        		board.push_back(line);
        	}
        	ret.push_back(board);
        }

        return ret;
    }
private:
	vector<vector<int>> record;
	void gao(vector<int>& vt, int row, int n)
	{
		if (row == n)
		{
			record.push_back(vt);
			return ;
		}

		for (int j = 0; j < n; ++ j)
		{
			bool legal = true;
			for (int i = 0; i < row; ++ i)
			{
				if (vt[i]==j || i-vt[i]==row-j || i+vt[i]==row+j)
				{
					legal = false;
					break;
				}
			}
			if (legal == true)
			{
				vt[row] = j;
				gao(vt, row+1, n);
			}
		}
	}
};