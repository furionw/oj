// Copyright 2017 Qi Wang
// Date: 2017-11-07
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0) {
      if (nums1[i] > nums2[j]) {
        nums1[i + j + 1] = nums1[i];
        --i;
      } else {
        nums1[i + j + 1] = nums2[j];
        --j;
      }
    }
    for (; j >= 0; --j) {
      nums1[j] = nums2[j];
    }
  }
};

// Date: 2017-08-15
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, idx = m + n - 1;
    for (; i >= 0 && j >= 0;
       nums1[idx--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--]) {}
    for (; j >= 0; nums1[idx--] = nums2[j--]) {}
  }
};

// Date: 2017-07-14
// Actually the solution on 2016-12-17 is better I think
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (int i = m - 1; i >= 0; --i)
      nums1[i + n] = nums1[i];
    int i = 0, j = 0, idx = 0;
    while (i < m && j < n) {
      if (nums1[i + n] < nums2[j]) {
        nums1[idx++] = nums1[i++ + n];
      } else {
        nums1[idx++] = nums2[j++];
      }
    }
    for (; i < m; ++i) nums1[idx++] = nums1[i + n];
    for (; j < n; ++j) nums1[idx++] = nums2[j];
  }
};

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