// 2025-07-17
class Foo {
 public:
  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    finishedFirst_.test_and_set();
    finishedFirst_.notify_one();
  }

  void second(function<void()> printSecond) {
    while (!finishedFirst_.test()) {
      finishedFirst_.wait(false);
    }
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    finishedSecond_.test_and_set();
    finishedSecond_.notify_one();
  }

  void third(function<void()> printThird) {
    while (!finishedSecond_.test()) {
      finishedSecond_.wait(false);
    }
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }

 private:
  atomic_flag finishedFirst_;
  atomic_flag finishedSecond_;
};
