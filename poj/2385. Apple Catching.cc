// Copyright 2017 Qi Wang
// Date: 2017-05-11
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
  int t, w;
  cin >> t >> w;
  vector<vector<int> > dp(2, vector<int>(w + 2, 0));
  for (int i = 1; i <= t; ++i) {
    int apple_tree;
    cin >> apple_tree;
    --apple_tree;
    vector<vector<int> > next = dp;
    for (int tree = 0; tree < 2; ++tree)
      for (int walk = 0; walk <= w; ++walk)
        next[tree][walk] = max(next[tree][walk], dp[!tree][walk + 1])
            + (tree == apple_tree);
    swap(dp, next);
  }
  int result = 0;
  for (int tree = 0; tree < 2; ++tree)
    for (int walk = 0; walk <= w; ++walk)
      result = max(result, dp[tree][walk]);
  cout << result << endl;
}
