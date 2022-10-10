// Date: 2022-10-06
// Method 1: priority queue
struct People {
  People() {}
  People(const string& n, int h): n(n), h(h) {} 
  string n;
  int h;
  bool operator<(const People& other) const {
    return h < other.h;
  }
};

class Solution {
 public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    priority_queue<People, vector<People>> pq;
    for (size_t i = 0; i < names.size(); ++i) {
      pq.emplace(names[i], heights[i]);
    }
    vector<string> result;
    result.reserve(names.size());
    for (; !pq.empty(); pq.pop()) {
      result.push_back(pq.top().n);
    }
    return result;
  }
};

// Date: 2022-10-06
// Method 2: quick sort implementation
class Solution {
 public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    qsort(names, heights, 0, names.size());
    return names;
  }

 private:
  void qsort(vector<string>& names, vector<int>& heights, int l, int r) {
    if (l + 1 >= r) {
      return;
    }
    int pivot = l;
    for (size_t i = l + 1; i < r; ++i) {
      if (heights[i] > heights[pivot]) {
        swap(heights[i], heights[pivot + 1]);
        swap(heights[pivot + 1], heights[pivot]);
        swap(names[i], names[pivot + 1]);
        swap(names[pivot + 1], names[pivot]);
        ++pivot;
      }
    }
    qsort(names, heights, l, pivot);
    qsort(names, heights, pivot + 1, r);
  }
};
