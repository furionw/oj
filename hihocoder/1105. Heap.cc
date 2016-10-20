// Copyright 2016 Qi Wang
// Date: 2016-10-18
#include <iostream>
#include <cassert>
#include <utility>
#include <climits>

using std::swap;
using std::cin; using std::cout; using std::endl;

constexpr int MAXN = 1e5 + 1;

// MAX HEAP
class Heap {
 public:
  inline int top() const { return elems_[1]; };

  inline void pop() {
    assert(size_ != 0);
    swap(elems_[1], elems_[size_--]);
    if (size_ != 0) max_heapify(1);
  }

  void push(int elem) {
    // We should not use ++size_ in assert, 'cause it might be ignored in release version
    assert(size_ + 1 < MAXN);
    elems_[++size_] = INT_MIN;
    increase_key(size_, elem);
  }

 private:
  inline int parent(int idx) const { return idx / 2; }

  inline int left(int idx) const { return 2 * idx; }

  inline int right(int idx) const { return 2 * idx + 1; }

  void max_heapify(int idx) {
    int max_idx = idx;
    int l = left(idx), r = right(idx);
    max_idx = l <= size_ && elems_[l] > elems_[max_idx] ? l : max_idx;
    max_idx = r <= size_ && elems_[r] > elems_[max_idx] ? r : max_idx;
    if (max_idx != idx) {
      swap(elems_[idx], elems_[max_idx]);
      max_heapify(max_idx);
    }
  }

  void increase_key(int idx, int key) {
    if (idx > 1 && elems_[parent(idx)] < key) {
      swap(elems_[parent(idx)], elems_[idx]);
      increase_key(parent(idx), key);
    } else {
      elems_[idx] = key;
    }
  }

  int elems_[MAXN];
  int size_ = 0;
};

int main() {
  Heap heap;
  int n;
  cin >> n;
  while (n--) {
    char c;
    cin >> c;
    if (c == 'A') {
      int weight;
      cin >> weight;
      heap.push(weight);
    } else {
      cout << heap.top() << endl;
      heap.pop();
    }
  }
}
