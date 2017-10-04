// Copyright 2017 Qi Wang
// Date: 2017-10-03
// push(5), push(4), min(), push(4), pop(), min(), push(6), pop()
//       -,       -,     4,       -,     4,     4,       -,     6
class MinStack {
 public:
  MinStack() {}
 
  void push(int number) {
    if (min_stk_.empty() || number <= min_stk_.top()) min_stk_.push(number);
    num_stk_.push(number);
  }
 
  int pop() {
    int num = num_stk_.top();
    if (num == min_stk_.top()) min_stk_.pop();
    num_stk_.pop();
    return num;
  }
 
  int min() {
    return min_stk_.top();
  }
 
 private:
  stack<int> num_stk_;
  stack<int> min_stk_;
};
