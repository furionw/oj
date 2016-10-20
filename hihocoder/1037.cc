// Copyright 2016 Qi Wang
// Date: 2016-10-13
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::max_element;
using std::cin; using std::cout; using std::endl;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> cells(2, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      cin >> cells[1][j];
      cells[1][j] += max(cells[0][j - 1], cells[0][j]);
    }
    swap(cells[0], cells[1]);
  }
  cout << *max_element(cells[0].begin() + 1, cells[0].begin() + n + 1);
}
