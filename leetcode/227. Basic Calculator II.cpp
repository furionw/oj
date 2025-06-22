// 2025-06-20
// Method 2
// Refer to the Editorial
class Solution {
 public:
  int calculate(string s) {
    int n = s.size();
    int last = 0;
    int cur = 0;
    char lastSign = '+';
    int result = 0;
    for (int i = 0; i < n; ++i) {
      if (digit(s[i])) {
        cur = cur * 10 + (s[i] - '0');
      }
      // use `i != n - 1` to deal with trailing whitespace
      if (s[i] == '+' || s[i] == '-' ||
          s[i] == '*' || s[i] == '/' || i == n - 1) {
        if (lastSign == '+' || lastSign == '-') {
          result += last;
          last = lastSign == '+' ? cur : -cur;
        } else if (lastSign == '*') {
          last *= cur;
        } else if (lastSign == '/') {
          last /= cur;
        }
        cur = 0;
        lastSign = s[i];
      }
    }
    result += last;
    return result;
  }

 private:
  bool digit(char c) const {
    return '0' <= c && c <= '9';
  }
};

// 2025-06-20
// Method 1
class Solution {
 public:
  int calculate(string s) {
    // Remove spaces
    int cnt = 0;
    for (char c : s) {
      if (c != ' ') {
        s[cnt] = c;
        ++cnt;
      }
    }
    s.resize(cnt);

    int sign = 1;
    int result = 0;
    int operand = 0;
    for (int i = 0; i < s.size();) {
      char c = s[i];
      if (digit(c)) {
        operand = 10 * operand + (c - '0');
        ++i;
      } else if (c == '+') {
        result += sign * operand;
        sign = 1;
        operand = 0;
        ++i;
      } else if (c == '-') {
        result += sign * operand;
        sign = -1;
        operand = 0;
        ++i;
      } else if (c == '*' || c == '/') {
        bool mul = c == '*';
        int op2 = 0;
        // digit, * or /
        for (++i; i < s.size() && s[i] != '+' && s[i] != '-'; ++i) {
          if (digit(s[i])) {
            op2 = 10 * op2 + (s[i] - '0');
          } else {
            if (mul) {
              operand *= op2;
            } else {
              operand /= op2;
            }
            mul = s[i] == '*';
            op2 = 0;
          }
        }
        if (mul) {
          operand *= op2;
        } else {
          operand /= op2;
        }
        result += sign * operand;
        operand = 0;
      }
    }
    result += sign * operand;
    return result;
  }

 private:
  bool digit(char c) {
    return '0' <= c && c <= '9';
  }
};

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
