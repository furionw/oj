// Copyright 2016 Qi Wang
// Date: 2016-12-26
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    int cnt = 0;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int x1 = 0, y1 = 0, x2 = n - 1, y2 = n - 1; x1 <= x2, y1 <= y2;
        ++x1, ++y1, --x2, --y2) {
      for (int j = y1; j <= y2; ++j) matrix[x1][j] = ++cnt;
      for (int i = x1 + 1; i <= x2; ++i) matrix[i][y2] = ++cnt;
      for (int j = y2 - 1; x1 != x2 && j >= y1; --j) matrix[x2][j] = ++cnt;
      for (int i = x2 - 1; y1 != y2 && i > x1; --i) matrix[i][y1] = ++cnt;
    }
    return matrix;
  }
};

// Date: 2014-07
class Solution 
{
public:
    vector<vector<int> > generateMatrix(int n) 
    {
    	vector<vector<int>> ret;
    	int x1=0, y1=0, x2=n-1, y2=n-1, cnt=1;

    	for (int i = 0; i < n; ++ i)
    	{
    		vector<int> line(n, 0);
    		ret.push_back(line);
    	}
    	for ( ; x1<=x2 && y1<=y2; ++x1, ++y1, --x2, --y2)
    	{
    		for (int j = y1;   j <= y2; ret[x1][j++] = cnt++) {}
    		for (int i = x1+1; i <= x2; ret[i++][y2] = cnt++) {}
    		for (int j = y2-1; x1!=x2 && j>=y1;   ret[x2][j--] = cnt++) {}
    		for (int i = x2-1; y1!=y2 && j>=x1+1; ret[i--][y1] = cnt++) {}    
    	}

    	return ret;
    }
};
