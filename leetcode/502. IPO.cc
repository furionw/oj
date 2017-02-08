// Copyright 2017 Qi Wang
// Date: 2017-02-08
// Refer to: https://discuss.leetcode.com/topic/77768/very-simple-greedy-java-solution-using-two-priorityqueues
// pair<int, int> : <capital, profit>
template <bool cap>
struct Comp {
  bool operator ()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
    if (cap) {
      return lhs.first != rhs.first ?
          lhs.first > rhs.first : lhs.second < rhs.second;
    } else {
      return lhs.second != rhs.second ?
          lhs.second < rhs.second : lhs.first > rhs.first;
    }
  }
};

class Solution {
 public:
  int findMaximizedCapital(int k, int w, vector<int>& profits,
      vector<int>& capital) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp<true>> caps;
    for (size_t i = 0; i < profits.size(); ++i)
      caps.emplace(capital[i], profits[i]);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp<false>> pros;
    for (int i = 0; i < k; ++i) {
      for (; !caps.empty() && caps.top().first <= w; caps.pop())
        pros.push(caps.top());
      if (pros.empty()) break;
      w += pros.top().second;
      pros.pop();
    }
    return w;
  }
};
