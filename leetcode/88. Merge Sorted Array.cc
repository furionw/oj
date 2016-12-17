// Copyright 2016 Qi Wang
// Date: 2016-12-17
// Refer to one of the top solutions
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0)
      nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    for (; j >= 0; nums1[k--] = nums2[j--]) {}
  }
};

// Date: 2016-12-17
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (m + n == 0) return;
    vector<int> res(m + n);
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
      if (nums1[i] < nums2[j]) {
        res[k++] = nums1[i++];
      } else {
        res[k++] = nums2[j++];
      }
    }
    for (; i < m; res[k++] = nums1[i++]) {}
    for (; j < n; res[k++] = nums2[j++]) {}
    nums1 = res;
  }
};

// Date: 2014-08
class Solution 
{
public:
    void merge(int A[], int m, int B[], int n) 
    {
      int i=0, j=0, index=m;
      vector<int> vt(m+n, 0);
      while ( i<m && j<n )
      {
        if (A[i] < B[j])
        {
          vt[index ++] = A[i ++];
        } else
        {
          vt[index ++] = B[j ++];
        }
      }
      for ( ; i < m; vt[index ++] = A[i ++]) {}
      for ( ; j < n; vt[index ++] = B[j ++]) {}
      for (i = 0; i < n+m; ++ i)
      {
        A[i] = vt[i];
      }
    }
};