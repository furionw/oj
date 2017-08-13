// Copyright 2017 Qi Wang
// Date: 2017-08-12
// Method 2
class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<pair<int, int>> dist_and_num_arr(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
      dist_and_num_arr[i] = make_pair(abs(arr[i] - x), arr[i]);
    }
    sort(dist_and_num_arr.begin(), dist_and_num_arr.end());
    vector<int> result(k);
    for (int i = 0; i < k; ++i) {
      result[i] = dist_and_num_arr[i].second;
    }
    sort(result.begin(), result.end());
    return result;
  }
};

// Date: 2017-08-12
// Method 1
struct comp {
  bool operator() (int a, int b) {
    return abs(a) != abs(b) ? abs(a) > abs(b) : a > b;
  }
};

class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<int, vector<int>, comp> pq;
    for (int num : arr) {
      pq.push(num - x);
    }
    vector<int> result;
    for (int i = 0; i < k; ++i) {
      result.push_back(pq.top() + x);
      pq.pop();
    }
    sort(result.begin(), result.end());
    return result;
  }
};