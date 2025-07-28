// 2025-07-27
class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> inQ;
    unordered_set<string> deads;
    queue<string> q;
    for (const auto& d : deadends) {
      deads.insert(d);
    }

    if (deads.contains("0000")) {
      return -1;
    } else if (target == "0000") {
      return 0;
    }

    q.push("0000");
    inQ.insert("0000");
    for (int cnt = 1; !q.empty(); ++cnt) {
      queue<string> next;
      while (!q.empty()) {
        auto pwd = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
          static vector<int> directions {-1, 1};
          for (int d : directions) {
            char c = (pwd[i] - '0' + 10 + d) % 10 + '0';
            swap(pwd[i], c);
            if (pwd == target) {
              return cnt;
            } else if (!deads.contains(pwd) && !inQ.contains(pwd)) {
              next.push(pwd);
              inQ.insert(pwd);
            }
            swap(pwd[i], c);
          }
        }
      }
      q = move(next);
    }
    return -1;
  }
};
