// Copyright 2017 Qi Wang
// Date: 2017-07-17
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int* a = nums1.data();
    const int* b = nums2.data();
    int m = nums1.size(), n = nums2.size();
    return ((m + n) & 1)
        ? Find(a, m, b, n, (m + n) / 2 + 1)
        : (Find(a, m, b, n, (m + n) / 2) + Find(a, m, b, n, (m + n) / 2 + 1))
              / 2;
  }

 private:
  double Find(const int* a, int m, const int* b, int n, int p) const {
    if (0 == m) {
      return b[p - 1];
    } else if (m > n) {
      return Find(b, n, a, m, p);
    } else if (1 == p) {
      return a[0] < b[0] ? a[0] : b[0];
    } else {
      int i = min(p / 2, m) - 1;
      int j = p - i - 2;
      return a[i] < b[j]
          ? Find(a + i + 1, m - i - 1, b, n, p - i - 1)
          : Find(a, m, b + j + 1, n - j - 1, p - j - 1);
    }
  }
};

// Date: 2016-12-18
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = static_cast<int>(nums1.size()), n = static_cast<int>(nums2.size());
    const int *a = nums1.data(), *b = nums2.data();
    return m + n & 1
        ? kth(a, m, b, n, (m + n >> 1) + 1)  // odd
        : (kth(a, m, b, n, m + n >> 1)
            + kth(a, m, b, n, (m + n >> 1) + 1)) / 2.;  // even
  }

 private:
  int kth(const int *a, int m, const int *b, int n, int k) const {
    if (m > n) {
      // using swap instead of calling another kth() might be faster
      swap(a, b);
      swap(m, n);
    }
    if (m == 0) {
      return b[k - 1];
    } else if (k == 1) {
      return min(a[0], b[0]);
    }
    int pa = min(m, k / 2);
    int pb = k - pa;
    return a[pa - 1] == b[pb - 1]
        // when they are equal, we don't bother calling kth() again
        ? a[pa - 1] : a[pa - 1] < b[pb - 1]
            ? kth(a + pa, m - pa, b, n, k - pa)
            : kth(a, m, b + pb, n - pb, k - pb);
  }
};

// Date: 2016-03
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int sz = nums1.size() + nums2.size();
    if (sz % 2 == 0)
        return (find_kth(nums1.data(), nums1.size(), nums2.data(), nums2.size(), sz / 2)
          + find_kth(nums1.data(), nums1.size(), nums2.data(), nums2.size(), sz / 2 + 1)) / 2;
    else 
      return find_kth(nums1.data(), nums1.size(), nums2.data(), 
        nums2.size(), sz / 2 + 1);
    }

private:
  double find_kth(const int *a, size_t m, const int *b, size_t n, size_t k) {
    if (m > n)
      return find_kth(b, n, a, m, k);
    else if (m == 0)
      return b[k-1];
    else if (k == 1)
      return min(a[0], b[0]);

    size_t pa = min(m, k/2);
    size_t pb = k - pa; // find out the evaluation order of commma operator, plz
    if (a[pa-1] < b[pb-1])
      return find_kth(a+pa, m-pa, b, n, k-pa);
    else if (a[pa-1] > b[pb-1])
      return find_kth(a, m, b+pb, n-pb, k-pb);
    else
      return a[pa-1];
  }
};

// Date: 2014-06
class Solution 
{
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) 
    {
      if ((m+n) % 2 == 1)
      {
        return find_kth(A,m,B,n,(m+n)/2+1);
      } else // even
      {
        return (find_kth(A,m,B,n,(m+n)/2)+find_kth(A,m,B,n,(m+n)/2+1)) / 2.0;
      }
    }

private:
  int find_kth(int A[], int m, int B[], int n, int k)
  {
    if (m == 0)
    {
      return B[k-1];
    } else if (m > n) // maintain m < n
    {
      return find_kth(B, n, A, m, k);
    } else if (k == 1)
    {
      return min(A[0], B[0]);
    }
    int pa = min(k/2, m), pb = k-pa;
    if (A[pa-1] < B[pb-1])
    {
      return find_kth(A+pa, m-pa, B, n, k-pa); // maintain pointers and k-th here
    } else if (A[pa-1] > B[pb-1])
    {
      return find_kth(A, m, B+pb, n-pb, k-pb); // maintain pointers and k-th here
    } else
    {
      return A[pa-1];
    }
  }
};