// 2025-07-26
class Solution {
 public:
  int findTheWinner(int n, int k) {
    list<int> l;
    for (int i = 1; i <= n; ++i) {
      l.push_back(i);
    }

    for (auto it = l.begin(); l.size() > 1;) {
      for (int cnt = k - 1; cnt > 0; --cnt) {
        if (++it == l.end()) {
          it = l.begin();
        }
      }
      auto next = it;
      if (++next == l.end()) {
        next = l.begin();
      }
      l.erase(it);
      it = next;
    }

    return l.front();
  }
};
