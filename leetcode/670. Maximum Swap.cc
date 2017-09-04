// Copyright 2017 Qi Wang
// Date: 2017-09-03
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
