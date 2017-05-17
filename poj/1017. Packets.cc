// Copyright 2017 Qi Wang
// Date: 2017-05-17
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int cnt[7][7], num[7];
  while (true) {
    for (int i = 1; i <= 6; ++i)
      cin >> num[i];
    bool all_zero = true;
    for (int i = 1; i <= 6 && all_zero; ++i)
      all_zero = 0 == num[i];
    if (all_zero) break;
    memset(cnt, 0, sizeof cnt);
    int result = num[6] + num[5] + num[4];
    int one_cnt = num[5] * 11;
    int two_cnt = num[4] * 5;
    // 3*3
    result += ceil(num[3] / 4.);
    switch (4 - (num[3] % 4)) {
      case 1:
        two_cnt += 1;
        one_cnt += 5;
        break;
      case 2:
        two_cnt += 3;
        one_cnt += 6;
        break;
      case 3:
        two_cnt += 5;
        one_cnt += 7;
        break;
    }
    // 2*2
    if (two_cnt >= num[2]) {
      one_cnt += (two_cnt - num[2]) * 2;
    } else {
      num[2] -= two_cnt;
      result += ceil(num[2] / 9.);
      if (0 != num[2] % 9)
        one_cnt += (9 - (num[2] % 9)) * 4;
    }
    // 1*1
    if (one_cnt < num[1]) {
      result += ceil((num[1] - one_cnt) / 36.);
    }
    cout << result << endl;
  }
}
