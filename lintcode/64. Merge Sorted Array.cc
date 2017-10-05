// Copyright 2017 Qi Wang
// Date: 2017-10-05
class Solution {
 public:
  void mergeSortedArray(int A[], int m, int B[], int n) {
    int i = m - 1, j = n - 1, idx = m + n - 1;
    while (i >= 0 && j >= 0) {
      if (A[i] > B[j]) {
        A[idx--] = A[i--];
      } else {
        A[idx--] = B[j--];
      }
    }
    if (j >= 0) {
      copy(B, B + j + 1, A);
    }
  }
};
