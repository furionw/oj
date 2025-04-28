// 2025-04-27
// Method 1
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> leftmost(101, -1);
    int n = temperatures.size();
    vector<int> result(n, 0);
    
    for (int i = n - 1; i >= 0; --i) {
      int temp = temperatures[i];
      leftmost[temp] = i;
      int minDist = n;
      for (int j = temp + 1; j <= 100; ++j) {
        if (leftmost[j] != -1) {
          minDist = min(minDist, leftmost[j] - i);
        }
      }
      if (minDist != n) {
        result[i] = minDist;
      }
    }

    return result;
  }
};

// 2025-04-27
// Method 2: monotonic stack
struct Node {
  int t;
  int idx;
};

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);

    if (n == 1) {
      return result;
    }

    stack<Node> stk;
    for (int i = n - 1; i >= 0; --i) {
      int t = temperatures[i];
      for (; !stk.empty() && stk.top().t <= t; stk.pop()) {}
      if (!stk.empty()) {
        result[i] = stk.top().idx - i;
      }
      stk.push({
        .t = t,
        .idx = i
      });
    }

    return result;
  }
};