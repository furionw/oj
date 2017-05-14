// Copyright 2017 Qi Wang
// Date: 2017-05-13
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> skewers;
  for (int i = 0; i < (n << 1); ++i) {
    int skewer;
    cin >> skewer;
    skewers.push_back(skewer);
  }
  sort(skewers.begin(), skewers.end());
  int result = 0;
  for (int i = 0; i < (n << 1); i += 2)
    result += skewers[i];
  cout << result << endl;
}
