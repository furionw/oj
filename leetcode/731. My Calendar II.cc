// 2025-05-04
// Method 1
// Refer to the Editorial.
// Time complexity -- high
class MyCalendarTwo {
 public:
  bool book(int b2, int e2) {
    for (const auto& [b1, e1] : obks) {
      if (overlap(b1, e1, b2, e2)) {
        return false;
      }
    }

    for (const auto& [b1, e1] : bks) {
      auto [ob1, oe1] = getOverlap(b1, e1, b2, e2);
      obks.emplace_back(ob1, oe1);
    }

    bks.emplace_back(b2, e2);
    return true;
  }

 private:
  bool overlap(int b1, int e1, int b2, int e2) const {
    return max(b1, b2) < min(e1, e2);
  }

  pair<int, int> getOverlap(int b1, int e1, int b2, int e2) const {
    return {max(b1, b2), min(e1, e2)};
  }

  vector<pair<int, int>> bks;
  vector<pair<int, int>> obks;
};
