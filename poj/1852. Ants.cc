// Copyright 2017 Qi Wang
// Date: 2017-05-05
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, n;
    cin >> l >> n;
    vector<int> ants(n);
    for (size_t i = 0; i < n; ++i) cin >> ants[i];
    int minimal = 0, maximal = 0;
    for (size_t i = 0; i < n; ++i) {
      minimal = max(minimal, min(ants[i], l - ants[i]));
      maximal = max(maximal, max(ants[i], l - ants[i]));
    }
    cout << minimal << " " << maximal << endl;
  }
}
