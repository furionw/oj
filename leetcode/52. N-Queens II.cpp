class Solution 
{
public:
    int totalNQueens(int n) 
    {
        vector<int> vt(n, 0);
        gao(vt, 0, n);
        return cnt;
    }
private:
	int cnt;
	void gao(vector<int>& vt, int row, int n)
	{
		if (row == n)
		{
			++ cnt;
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