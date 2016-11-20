// Problem 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  // Input
  bool odd = true;
  vector<int> odds;
  vector<int> evens;
  for (int num; cin >> num; odd = !odd)
    [](vector<int>& vt, int num) { vt.push_back(num); }
        (odd? odds: evens, num);

  // Sort
  sort(odds.begin(), odds.end());
  sort(evens.begin(), evens.end(), [](int a, int b) { return a > b; });

  // Output
  odd = true;
  for (size_t odd_idx = 0, even_idx = 0;
      odd_idx < odds.size() || even_idx < evens.size(); odd = !odd)
    [](vector<int>& vt, int& idx) { cout << vt[idx ++] << ' '; }
        (odd? odds: even, odd? odd_idx: even_idx);
}
