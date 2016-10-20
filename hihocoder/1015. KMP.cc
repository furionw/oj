// Copyright 2016 Qi Wang
// Date: 2016-10-12
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> computePrefixFunction(const string& s) {
  vector<int> pi(s.size(), 0);
  for (size_t i = 1; i < s.size(); ++i) {
    int len = pi[i - 1];
    for (; len != 0 && s[len] != s[i]; len = pi[len - 1]) {}
    pi[i] = len + (s[len] == s[i] ? 1 : 0);
  }
  return pi;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    string needle, haystack;
    cin >> needle >> haystack;
    vector<int> pi = computePrefixFunction(needle);
    int cnt = 0, len = 0;
    for (size_t i = 0; i < haystack.size(); ++i) {
      for (; len != 0 && haystack[i] != needle[len]; len = needle[len - 1]) {}
      len = len + (haystack[i] == needle[len] ? 1 : 0);
      if (len == needle.size()) {
        ++cnt;
        len = needle[len];
      }
    }
    cout << cnt << endl;
  }
}
