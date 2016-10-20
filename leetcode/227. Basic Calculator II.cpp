// Copyright 2016 Stephen Wong
// Date: 2016-09-27
class Solution {
 public:
  int calculate(string s) {
    stack<int> nums;
    stack<char> signs;
    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] >= '0' && s[i] <= '9') {
        int num = s[i++] - '0';
        while (s[i] >= '0' && s[i] <= '9')
          num = 10 * num + s[i++] - '0';
        nums.push(num);
        --i;
      } else if (s[i] != ' ') {
        eval(nums, signs, getPriority(s[i]));
        signs.push(s[i]);
      }
    }
    // Evaluate all the remaining operations
    eval(nums, signs, getPriority('+'));
    return nums.top();
  }

 private:
  inline void eval(stack<int>& nums, stack<char>& signs, int priority) const {
    while (!signs.empty() && getPriority(signs.top()) >= priority)
      eval(nums, signs);
  }

  inline void eval(stack<int>& nums, stack<char>& signs) const {
    int op2 = nums.top();
    nums.pop();
    int op1 = nums.top();
    nums.pop();
    switch (signs.top()) {
      case '+':
        nums.push(op1 + op2);
        break;
      case '-':
        nums.push(op1 - op2);
        break;
      case '*':
        nums.push(op1 * op2);
        break;
      case '/':
        nums.push(op1 / op2);
        break;
      default:
        assert(false);
    }
    signs.pop();
  }

  // '*' and '/' have priority 1,
  // while '+' and '-' have 0.
  inline int getPriority(char sign) const {
    return sign == '*' || sign == '/';
  }
};
