// Copyright 2017 Qi Wang
// Date: 2017-04-10
// Refer to: http://blog.csdn.net/gxh27954/article/details/69788317
// The correctness has been proved on my own.
#include <iostream>
#include <cstdint>

using namespace std;

int main() {
  uint64_t n, q;
  cin >> n >> q;
  uint64_t result = n;
  for (int k = 1; ; ++k) {
    uint64_t robots = 1 << k;
    if (robots > n) break;
    if (n % robots == 0) {
      result = min(result, n / robots + k * q);
    } else {
      result = min(result, n / robots + 1 + k * q);
    }
  }
  cout << result << endl;
}
