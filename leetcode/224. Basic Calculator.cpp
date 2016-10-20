// Copyright 2016 Qi Wang
// Refer to https://discuss.leetcode.com/topic/15806/easy-18-lines-c-16-lines-python
// Date: 2016-09-27
class Solution {
 public:
  int calculate(string s) {
    int res = 0;
    // We do have to use "2" here to handle the 1+1 case.
    vector<int> signs(2, 1);
    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] >= '0' && s[i] <= '9') {
        int num = 0;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9')
          num = num * 10 + s[i++] - '0';
        res += signs.back() * num;
        signs.pop_back();
        --i;
      } else if (s[i] == '(') {
        signs.push_back(signs.back());
      } else if (s[i] == ')') {
        signs.pop_back();
      } else if (s[i] != ' ') {
        signs.push_back(s[i] == '-'? -1 * signs.back(): signs.back());
      }
    }
    return res;
  }
};

// Two stacks
// Date: 2016-09-27
class Solution {
 public:
  int calculate(string s) {
    stack<int> nums;
    stack<char> signs;
    for (int i = 0; i < s.size(); ++i) {
      switch (s[i]) {
        case ' ':
          continue;
        case '+':
        case '-':
        case ')':
          eval(nums, signs, s[i]);
          break;
        case '(':
          signs.push(s[i]);
          break;
        default:
          // parse number
          nums.push(eval(s, i));
          --i;  // counteract the effect of ++i
      }
    }
    if (!signs.empty()) eval(nums, signs);
    return nums.top();
  }

 private:
  inline void eval(const stack<int>& nums, const stack<char>& signs) const {
    int op2 = nums.top();
    nums.pop();
    int op1 = nums.top();
    nums.pop();
    nums.push(signs.top() == '+'? op1 + op2 : op1 - op2);
    signs.pop();
  }

  inline void eval(const stack<int>& nums, const stack<char>& signs, char input)
      const {
    while (!signs.empty()) {
      if (signs.top() == '(') {
        if (input == ')') {
          signs.pop();
        } else {
          signs.push(input);
        }
        return;
      } else {
        eval(nums, signs);
      }
    }
    signs.push(input);
  }

  inline int eval(const string& s, const int& idx) const {
    int num = 0;
    for ( ; idx < s.size() && s[idx] >= '0' && s[idx] <= '9'; ++idx)
      num = 10 * num + s[idx] - '0';
    return num;
  }
};
