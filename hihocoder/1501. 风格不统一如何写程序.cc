// Copyright 2017 Qi Wang
// Date: 2017-04-15
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

inline string SnakeToCamel(const string& snake) {
  string camel;
  bool is_begin = false;
  for (char c : snake) {
    if (c == '_') {
      is_begin = true;
    } else {
      camel += is_begin ? c - 'a' + 'A' : c;
      is_begin = false;
    }
  }
  return camel;
}

inline string CamelToSnake(const string& camel) {
  string snake;
  for (char c : camel) {
    // lowercase
    if ('a' <= c && c <= 'z') {
      snake += c;
    // uppercase
    } else {
      snake += '_';
      snake += c - 'A' + 'a';
    }
  }
  return snake;
}

inline bool IsSnake(const string& str) {
  return str.find('_') != string::npos;
}

inline bool Iscamel(const string& str) {
  return any_of(str.begin(), str.end(), [](char c) {
    return 'A' <= c && c <= 'Z';
  });
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    string str;
    cin >> str;
    if (IsSnake(str)) {
      str = SnakeToCamel(str);
    } else if (Iscamel(str)) {
      str = CamelToSnake(str);
    }
    cout << str << endl;
  }
}
