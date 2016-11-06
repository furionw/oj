// Copyright 2016 Qi Wang
// Date: 2016-11-06
#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

inline int cmp(const list<size_t>& lhs, const list<size_t>& rhs) {
  if (lhs.size() < rhs.size()) {
    return -1;
  } else if (lhs.size() > rhs.size()) {
    return 1;
  } else {
    for (auto it1 = lhs.begin(), it2 = rhs.begin(); it1 != lhs.end();
        ++it1, ++it2) {
      if (*it1 < *it2) {
        return -1;
      } else if (*it1 > *it2) {
        return 1;
      }
    }
    return 0;
  }
}

inline list<size_t> getMax() {
  static list<size_t> res;
  if (res.empty()) {
    for (size_t i = 0; i < 62; ++i)
      res.push_back(1);
  }
  return res;
}

inline list<size_t> convert(size_t n, size_t base) {
  list<size_t> res;
  for (; n; n /= base)
    res.push_front(n % base);
  return res;
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int t = 1; t <= tt; ++t) {
    size_t n;
    cin >> n;
    for (auto allOneExpr = getMax(); !allOneExpr.empty();
        allOneExpr.erase(allOneExpr.begin())) {
      size_t l = 2, r = n;
      size_t base = 1;
      while (l <= r) {
        size_t mid = (l + r) >> 1;
        auto expr = convert(n, mid);
        int flag = cmp(expr, allOneExpr);
        if (flag == -1) {
          // base is too large
          r = mid - 1;
        } else if (flag == 1) {
          // base is too small
          l = mid + 1;
        } else {
          base = mid;
          break;
        }
      }
      if (base != 1) {
        // Note that the 'C' should be upper case.
        cout << "Case #" << t << ": " << base << endl;
        break;
      }      
    }
  }
}
