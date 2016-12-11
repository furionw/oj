// Copyright 2016 Qi Wang
// Date: 2016-12-11
#include <string>
#include <numeric>

using std::string;

inline bool lowercase(char c) { return 'a' <= c && c <= 'z'; }

inline bool alpha_numerical(char c) {
  return lowercase(c)
      || ('A' <= c && c <= 'Z')
      || ('0' <= c && c <= '9');
}

inline char capitalize(char c) {
  constexpr static char OFFSET = 'a' - 'A';
  return lowercase(c) ? c - OFFSET : c;
}

inline void pack(string& res, int& i, const string& S, int& j, int remainder) {
  while (remainder--) {
    while (S[j] == '-') ++j;
    res[i++] = capitalize(S[j++]);
  }
}

string solution(string &S, int K) {
  int cCnt = std::accumulate(S.begin(), S.end(), 0, [](int prev, char c) {
    return prev + static_cast<int>(alpha_numerical(c));
  });
  int gCnt = cCnt / K;
  int remainder = cCnt % K;
  string res(remainder
      ? (K * gCnt + remainder + gCnt)  // Have remainder
      : (K * gCnt + gCnt - 1), 0);  // Without remainder
  int i = 0, j = 0;
  if (remainder) {
    pack(res, i, S, j, remainder);
    res[i++] = '-';
  }
  while (gCnt--) {
    pack(res, i, S, j, K);
    if (gCnt) res[i++] = '-';
  }
  return res;
}
