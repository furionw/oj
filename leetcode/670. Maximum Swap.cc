// Copyright 2017 Qi Wang
// Date: 2017-10-19
class Solution {
 public:
  int maximumSwap(int num) {
    string s = to_string(num);
    for (int i = 0; i < s.size(); ++i) {
      int to_swap_idx = i;
      for (int j = i + 1; j < s.size(); ++j) {
        if (s[j] >= s[to_swap_idx]) {
          to_swap_idx = j;
        }
      }
      if (s[to_swap_idx] > s[i]) {
        swap(s[to_swap_idx], s[i]);
        break;
      }
    }
    return stoi(s);
  }
};

// Date: 2017-09-04
// Case 1: 577
class Solution {
 public:
  int maximumSwap(int num) {
    string origin = to_string(num);
    string largest = origin;
    sort(largest.begin(), largest.end(), greater<char>());
    for (int i = 0; i < origin.size(); ++i) {
      if (origin[i] != largest[i]) {
        int to_swap_idx = i + 1;
        for (int j = to_swap_idx + 1; j < origin.size(); ++j) {
          if (origin[j] >= origin[to_swap_idx]) {
            to_swap_idx = j;
          }
        }
        swap(origin[i], origin[to_swap_idx]);
        break;
      }
    }
    return stoi(origin);
  }
};

// Date: 2017-09-02
class Solution {
 public:
  int maximumSwap(int num) {
    string origin = to_string(num);
    string largest = origin;
    sort(largest.begin(), largest.end(), greater<char>());
    for (int i = 0; i < origin.size(); ++i) {
      if (origin[i] != largest[i]) {
        int to_swap_index = i + 1;
        for (int j = i + 2; j < origin.size(); ++j) {
          if (origin[j] >= origin[to_swap_index]) {
            to_swap_index = j;
          }
        }
        swap(origin[i], origin[to_swap_index]);
        break;
      }
    }
    return stoi(origin);
  }
};
