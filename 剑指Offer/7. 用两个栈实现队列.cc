// Copyright 2017 Qi Wang
// Date: 2017-09-04
// Jobdu 1512
#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

template<class T>
class Queue {
 public:
  void Push(int x) {
    store_stk_.push(x);
  }

  int Pop() {
    if (pop_stk_.empty()) {
      while (!store_stk_.empty()) {
        pop_stk_.push(store_stk_.top());
        store_stk_.pop();
      }
    }
    if (pop_stk_.empty()) {
      // cerr << "Pop from an empty queue." << endl;
      return -1;
    } else {
      int result = pop_stk_.top();
      pop_stk_.pop();
      return result;
    }
  }

 private:
  stack<T> pop_stk_;
  stack<T> store_stk_;
};

int main() {
  Queue<int> q;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    char str[5];
    scanf("%s", str);
    if (str[1] == 'U') {
      int num;
      cin >> num;
      q.Push(num);
    } else {
      cout << q.Pop() << endl;
    }
    getchar();
  }
}
