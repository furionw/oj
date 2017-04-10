// Copyright 2017 Qi Wang
// Date: 2017-04-10
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int n, r, c;
  cin >> n;
  vector<pair<int, int>> queens;
  unordered_map<int, uint64_t> rows, cols, diags, anti_diags;
  for (int i = 0; i < n; ++i) {
    cin >> r >> c;
    ++rows[r];
    ++cols[c];
    ++diags[r - c];
    ++anti_diags[r + c];
  }
  uint64_t result = 0;
  auto acc = [](const unordered_map<int, uint64_t>& cnts, uint64_t& result) {
    for (auto& p : cnts)
      result += p.second * (p.second - 1) >> 1;
  };
  acc(rows, result);
  acc(cols, result);
  acc(diags, result);
  acc(anti_diags, result);
  cout << result << endl;
}
