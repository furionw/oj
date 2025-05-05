// 2025-05-03
class Solution {
 public:
  vector<vector<int>> specialGrid(int N) {
    int num = 0;
    int sz = pow(2, N);
    vector<vector<int>> grid(sz, vector<int>(sz, 0));
    f(0, 0, sz, grid, num);
    return grid;
  }
  
 private:
  void f(
    int x, int y, int sz,
    vector<vector<int>>& grid, int& num) {
    if (sz == 1) {
      grid[x][y] = num;
      ++num;
      return;
    }
    // sz = 4
    // x = 0, y = 0
    f(x, y + sz / 2, sz / 2, grid, num);
    f(x + sz / 2, y + sz / 2, sz / 2, grid, num);
    f(x + sz / 2, y, sz / 2, grid, num);
    f(x, y, sz / 2, grid, num);
  }
};
