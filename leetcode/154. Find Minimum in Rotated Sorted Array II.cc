// Copyright 2017 Qi Wang
// Date: 2017-09-04
// Method 2: refer to the book <Offer>
class Solution {
 public:
  int findMin(vector<int> &num) {
    int l = 0, r = num.size() - 1, result_idx = 0;
    while (num[l] >= num[r]) {
      if (r - l <= 1) {
        result_idx = r;
        break;
      }
      int mid = l + r >> 1;
      if (num[l] == num[mid] && num[mid] == num[r]) {
        for (int i = l; i <= r; ++i) {
          result_idx = num[i] < num[result_idx] ? i : result_idx;
        }
        break;
      }
      if (num[l] <= num[mid]) {
        l = mid;
      } else if (num[mid] <= num[r]) {
        r = mid;
      }
    }
    return num[result_idx];
  }
};

// Date: 2017-09-04
// Method 1: refer to the previous solution
class Solution {
 public:
  int findMin(vector<int> &num) {
    return binary_search(0, num.size()-1, num);
  }

 private:
  int binary_search(int begin, int end, vector<int>& num) {
    int mid = begin + end >> 1;
    if (num[begin] < num[end] || end - begin <= 1) {
      return min(num[begin], num[end]);
    } else if (num[begin] < num[mid]) {
      return binary_search(mid + 1, end, num);
    } else if (num[begin] > num[mid]) {
      return binary_search(begin, mid, num); 
    } else {
      return binary_search(++begin, end, num);
    }
  }
};

// ...
class Solution
{
public:
  int findMin(vector<int> &num) 
  {
    return binary_search(0, num.size()-1, num);
  }
private:
  int binary_search(int begin, int end, vector<int>& num)
  {
    if (num[begin] < num[end] || end - begin <= 1)
    {
      return min(num[begin], num[end]);
    } else if (num[begin] < num[(begin+end)>>1])
    {
      return binary_search(((begin+end)>>1)+1, end, num);
    } else if (num[begin] > num[(begin+end)>>1])
    {
      return binary_search(begin, (begin+end)>>1, num); 
    } else
    {
      return binary_search(++begin, end, num);
    }
  }
};
