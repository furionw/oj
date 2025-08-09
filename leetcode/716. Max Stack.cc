// 2025-08-09
class MaxStack {
 public:
  void push(int x) {
    ++id_;
    stk_.emplace(x, id_);
    pq_.emplace(x, id_);
  }
  
  int pop() {
    while (removed_.contains(stk_.top().second)) {
      stk_.pop();
    }
    auto [x, id] = stk_.top();
    stk_.pop();
    removed_.insert(id);
    return x;
  }
  
  int top() {
    while (removed_.contains(stk_.top().second)) {
      stk_.pop();
    }
    return stk_.top().first;
  }
  
  int peekMax() {
    while (removed_.contains(pq_.top().second)) {
      pq_.pop();
    }
    return pq_.top().first;
  }
  
  int popMax() {
    while (removed_.contains(pq_.top().second)) {
      pq_.pop();
    }
    auto [x, id] = pq_.top();
    pq_.pop();
    removed_.insert(id);
    return x;
  }

 private:
  int id_ = 0;
  stack<pair<int, int>> stk_;
  priority_queue<pair<int, int>> pq_;
  unordered_set<int> removed_;
};
