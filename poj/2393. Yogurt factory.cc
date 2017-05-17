// Copyright 2017 Qi Wang
// Date: 2017-05-17
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, s;
  cin >> n >> s;
  vector<int> prices(n), demand(n);
  for (int i = 0; i < n; ++i)
    cin >> prices[i] >> demand[i];
  for (int i = 1, price = prices[0]; i < n; ++i)
    prices[i] = price = min(prices[i], price += s);
  long long acc = 0;
  for (int i = 0; i < n; ++i) acc += prices[i] * demand[i];
  cout << acc << endl;
}
