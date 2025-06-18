// 2025-06-17
class Solution {
 public:
  int nextGreaterElement(int n) {
    vector<int> digits;
    for (; n > 0; n /= 10) {
      digits.push_back(n % 10);
    }
    reverse(digits.begin(), digits.end());

    bool found = next_permutation(digits.begin(), digits.end());
    if (!found) {
      return -1;
    }
    
    long long next = 0;
    for (int d : digits) {
      next = next * 10 + d;
    }
    return next <= numeric_limits<int>::max()
        ? next
        : -1;
  }
};

// Date: 2017-04-21
class Solution {
 public:
  int nextGreaterElement(int n) {
    string str = to_string(n);
    if (next_permutation(str.begin(), str.end())) {
      try {
        return stoi(str);
      } catch(out_of_range e) {
        return -1;
      }
    } else {
      return -1;
    }
  }
};
