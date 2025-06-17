// 2025-06-16
// earliest task
struct ET {
  int enqueue;
  int idx;

  bool operator<(const ET& other) const {
    return enqueue > other.enqueue;
  }
};

// shortest task
struct ST {
  int processing;
  int idx;

  bool operator<(const ST& other) const {
    return processing != other.processing
        ? processing > other.processing
        : idx > other.idx;
  }
};

class Solution {
 public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    priority_queue<ET> et;
    priority_queue<ST> st;
    for (int i = 0; i < tasks.size(); ++i) {
      et.push({
        .enqueue = tasks[i][0],
        .idx = i
      });
    }
    long long clock = 0;
    vector<int> result;
    while (true) {
      if (!et.empty() && st.empty()) {
        clock = max(clock, static_cast<long long>(et.top().enqueue));
      }
      while (!et.empty() && et.top().enqueue <= clock) {
        auto t = et.top();
        et.pop();
        st.push({
          .processing = tasks[t.idx][1],
          .idx = t.idx
        });
      }
      if (st.empty()) {
        break;
      }
      int tIdx = st.top().idx;
      st.pop();
      result.push_back(tIdx);
      auto t = tasks[tIdx];
      clock = clock + t[1];
    }
    return result;
  }
};
