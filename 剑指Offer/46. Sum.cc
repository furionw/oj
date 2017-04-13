// Copyright 2017 Qi Wang
// Date: 2017-04-13
// Method 1
// Refer to 剑指Offer
class Solution {
 public:
  int Sum_Solution(int n) {
    shared_ptr<A> objs[2] = {make_shared<A>(), make_shared<B>()};
    return objs[1]->acc(n, objs);
  }

 private:
  struct A {
    virtual int acc(int n, shared_ptr<A> objs[2]) const { return 0; }
  };

  struct B : A {
    virtual int acc(int n, shared_ptr<A> objs[2]) const {
      return objs[!!n]->acc(n - 1, objs) + n;
    }
  };
};

// Date: 2017-04-13
// Method 2
// Refer to 剑指Offer
class Solution {
 private:
  struct A {
    A() { acc += ++cnt; }

    static void Reset() {
      cnt = 0;
      acc = 0;
    }

    static int cnt;
    static int acc;
  };

public:
  int Sum_Solution(int n) {
    A::Reset();
    A *as = new A[n];
    delete[] as;
    return A::acc;
  }
};

int Solution::A::cnt = 0;
int Solution::A::acc = 0;

// Date: 2017-04-13
// Method 3
// Refer to 剑指Offer
class Solution {
 public:
  int Sum_Solution(int n) {
    function<int(int)> funcs[2];
    funcs[0] = [](int n) { return 0; };
    funcs[1] = [&funcs](int n) { return funcs[!!n](n - 1) + n; };
    return funcs[1](n);
  }
};

// Date: 2017-04-13
// Method 4
class Solution {
 public:
  int Sum_Solution(int n) {
    // n should be determined in the compile time. Or this program won't compile
    return acc<10>();
  }

 private:
  template<int n>
  int acc() const { return acc<n - 1>() + n; }
 
  template<>
  int acc<1>() const { return 1; }
};
