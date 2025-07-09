// 2025-07-09
struct Room {
  long long end;
  int id;
};

class Solution {
 public:
  int mostBooked(int n, vector<vector<int>>& ms) {
    priority_queue<int, vector<int>, greater<int>> unused;
    for (int i = 0; i < n; ++i) {
      unused.push(i);
    }

    auto cmp = [](const Room& lhs, const Room& rhs) {
      return lhs.end != rhs.end
          ? lhs.end > rhs.end
          : lhs.id > rhs.id;
    };
    priority_queue<Room, vector<Room>, decltype(cmp)> rooms;

    int result = 0;
    vector<int> cnts(n, 0);
    sort(ms.begin(), ms.end());
    for (auto& m : ms) {
      for (; !rooms.empty() && rooms.top().end <= m[0]; rooms.pop()) {
        unused.push(rooms.top().id);
      }

      long long end = m[1];
      if (unused.empty()) {
        long long begin = rooms.top().end;
        int id = rooms.top().id;
        rooms.pop();
        unused.push(id);
        end = begin + m[1] - m[0];
      }


      int id = unused.top();
      unused.pop();
      rooms.push({
        .end = end,
        .id = id
      });

      int cnt = ++cnts[id];
      if (cnt > cnts[result]
          || (cnt == cnts[result] && id < result)) {
        result = id;
      }
    }
  
    return result;
  }
};
