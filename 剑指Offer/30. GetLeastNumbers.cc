// Copyright 2017 Qi Wang
// Date: 2017-04-06
class Solution {
 public:
  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if (k > input.size() || k <= 0) return vector<int>();
    for (int left = 0, right = input.size() - 1; left < right; ) {
      int pivot = input[left];
      int l = left, r = right;
      while (l < r) {
        for (; l < r && input[r] > pivot; --r) {}
        input[l] = input[r];
        for (; l < r && input[l] <= pivot; ++l) {}
        input[r] = input[l];
      }
      input[l] = pivot;
      if (l + 1 == k) {
        break;
      } else if (l + 1 < k) {
        left = l + 1;
      // l + 1 > k
      } else {
        right = r - 1;
      }
    }
    return vector<int>(input.begin(), input.begin() + k);
  }
};

// case 1
// input = {3, 1, 2, 5, 4}, k = 4
