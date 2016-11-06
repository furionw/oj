// Copyright 2016 Qi Wang
// Date: 2016-11-06
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  for (int t = 1; t <= tt; ++t) {
    string str;
    size_t I, J;
    cin >> str >> I >> J;
    size_t iCnt = (I - 1) / str.size();
    size_t jCnt = (J - 1) / str.size();
    long long res = 0;
    I = (I - 1) % str.size();
    J = (J - 1) % str.size();
    if (iCnt == jCnt) {
      for (size_t i = I; i <= J; ++i)
        res += str[i] == 'B';
    } else {
      size_t unitBlueCnt = 0;
      for (size_t i = 0; i < str.size(); ++i)
        unitBlueCnt += str[i] == 'B';
      for (size_t i = I; i < str.size(); ++i)
        res += str[i] == 'B';
      for (size_t i = 0; i <= J; ++i)
        res += str[i] == 'B';
      res += unitBlueCnt * (jCnt - iCnt - 1);
    }
    printf("case #%d: %lld\n", t, res);
  }
}
