#include <iostream>

using namespace std;

auto zero = [](auto f) {
  return [](auto x) {
    return x;
  };
};

auto succ = [=](auto m) {
  return [=](auto f) {
    return [=](auto x) {
      return m(f)(f(x));
    };
  };
};

auto add = [](auto m, auto n) {
  return [=](auto f) {
    return [=](auto x) {
      return m(f)(n(f)(x));
    };
  };
};

auto mul = [](auto m, auto n) {
  return [=](auto f) {
    return m(n(f));
  };
};

auto power = [=](auto m, auto n) {
  return [=](auto f) {
    return [=](auto x) {
      auto one = succ(zero);
      auto powerMul = [=](auto x) {
        return mul(m, x);
      };
      return n(powerMul(one))(f)(x);
    };
  };
};

auto inc = [](int x) { return x + 1; };

int main() {
  auto one = succ(zero);
  auto two = succ(one);
  auto three = add(one, two);
  auto four = mul(two, two);
  auto five = add(two, three);
  // 10
  auto ten = mul(two, five);
  cout << ten(inc)(0) << endl;
  // 100
  auto hundred = mul(ten, ten);
  cout << hundred(inc)(0) << endl;
  // 1e4
  cout << power(hundred, two)(inc)(0) << endl;
}
