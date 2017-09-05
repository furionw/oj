// Copyright 2017 Qi Wang
// Date: 2017-09-04
// Jobdu 1386
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
  int nums[1000000];
  for (int n; cin >> n; ) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", nums + i);
    }
    int l = 0, r = n - 1, result_idx = 0;
    while (nums[l] >= nums[r]) {
      if (r - l <= 1) {
        result_idx = r;
        break;
      }
      int mid = l + r >> 1;
      if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
        for (int i = l; i <= r; ++i) {
          result_idx = nums[i] < nums[result_idx] ? i : result_idx;
        }
        break;
      }
      if (nums[l] <= nums[mid]) {
        l = mid;
      } else if (nums[mid] <= nums[r]) {
        r = mid;
      }
    }
    printf("%d\n", nums[result_idx]);
  }
}
