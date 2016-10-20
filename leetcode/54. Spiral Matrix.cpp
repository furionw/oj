class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) 
    {
        if (matrix.empty() == true)
        {
            return vector<int>();
        }
        int x1 = 0, y1 = 0;
        int x2 = matrix.size()-1, y2 = matrix[0].size()-1;
        vector<int> ret;

        for ( ; x1<=x2 && y1<=y2; ++x1, ++y1, --x2, --y2)
        {
            for (int j = y1;   j <= y2; ret.push_back(matrix[x1][j++])) {} 
            for (int i = x1+1; i <= x2; ret.push_back(matrix[i++][y2])) {}
            for (int j = y2-1; x1!=x2 && j>=y1;   ret.push_back(matrix[x2][j--])) {} // x1!=x2
            for (int i = x2-1; y1!=y2 && i>=x1+1; ret.push_back(matrix[i--][y1])) {} // y1!=y2
        }

        return ret;
    }
};


/*#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) 
    {
    	if (matrix.empty() == true)
    	{
    		return vector<int>();
    	}

     	vector<int> ret;
     	int row = 0, column = 0;
     	int m = matrix.size(), n = matrix[0].size();
     	for ( ; row<m/2 && column<n/2; ++ row, ++ column)
     	{
     		for (int j = column; j < n-column; ++ j)
     		{
     			ret.push_back( matrix[row][j] );
     		}
     		for (int i = row+1; i < m-row; ++ i)
     		{
     			ret.push_back( matrix[i][n-column-1] );
     		}
     		for (int j = n-column-2; j >= column; -- j)
     		{
     			ret.push_back( matrix[m-row-1][j] );
     		}
     		for (int i = m-row-2; i >= row+1; -- i)
     		{
     			ret.push_back( matrix[i][column] );
     		}
     	}
     	if (m==n && m%2==1)
        {
            ret.push_back( matrix[row][column] );
		} else if (n%2==1 && row<m/2 && column>=n/2)
     	{
	     	for (int bound=m-row; row < bound; ++ row)
	     	{
	     		ret.push_back( matrix[row][column] );
	     	}
     	} else if (m%2==1 && row>=m/2 && column<n/2)
     	{
	     	for (int bound=n-column; column < bound; ++ column)
	     	{
	     		ret.push_back( matrix[row][column] );
	     	}
     	}

     	return ret;
    }
};

int main()
{
	vector<vector<int>> arg;
	vector<int> vt;
	vt.push_back( 2 );
	vt.push_back( 5 );
	vt.push_back( 8 );
	arg.push_back(vt);
	vt.clear();
	vt.push_back( 4 );
	vt.push_back( 0 );
	vt.push_back( -1 );
	arg.push_back(vt);
	Solution a;
	a.spiralOrder(arg);

	return 0;

}