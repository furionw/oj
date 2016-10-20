// Copyright 2016 Stephen Wong
// Date: 2016-09-29
class Queue {
 public:
  // Push element x to the back of queue.
  void push(int x) {
    s1.push(x);
  }

  // Removes the element from in front of queue.
  void pop() {
    tryToMoveS1ToS2();
    s2.pop();
  }

  // Get the front element.
  int peek() {
    tryToMoveS1ToS2();
    return s2.top();
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return s1.empty() && s2.empty();
  }

 private:
  inline void tryToMoveS1ToS2() {
    // Should not move when s2 is non-empty
    if (!s2.empty()) return;
    for (; !s1.empty(); s1.pop()) s2.push(s1.top());
  }
  stack<int> s1, s2;
};
