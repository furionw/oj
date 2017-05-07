// Copyright 2017 Qi Wang
// Date: 2017-05-07
// Refer to the book
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) cin >> nums[i];
  long long result = 0;
  while (n > 1) {
    int min1 = 0, min2 = 1;
    if (nums[min1] > nums[min2]) swap(min1, min2);
    for (int i = 2; i < n; ++i) {
      if (nums[i] <= nums[min1]) {
        min2 = min1;
        min1 = i;
      } else if (nums[i] < nums[min2]) {
        min2 = i;
      }
    }
    int t = nums[min1] + nums[min2];
    result += t;
    if (min1 == n - 1) swap(min1, min2);
    nums[min1] = t;
    nums[min2] = nums[n - 1];
    --n;
  }
  cout << result << endl;
}
