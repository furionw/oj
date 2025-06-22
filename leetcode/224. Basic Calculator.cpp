// 2025-06-20
// Refer to the Editorial
class Solution {
 public:
  int calculate(string s) {
    int result = 0;
    int sign = 1;
    int operand = 0;
    stack<int> stk;
    for (char c : s) {
      if (digit(c)) {
        operand = 10 * operand + (c - '0');
      } else if (c == '+') {
        result += sign * operand;
        sign = 1;
        operand = 0;
      } else if (c == '-') {
        result += sign * operand;
        sign = -1;
        operand = 0;
      } else if (c == '(') {
        stk.push(result); 
        stk.push(sign);
        sign = 1;
        result = 0;
      } else if (c == ')') {
        result += sign * operand;
        int tempSign = stk.top();
        stk.pop();
        int operand1 = stk.top();
        stk.pop();
        result = operand1 + tempSign * result;
        // doesn't matter
        // sign = 1;
        operand = 0;
      } else {
        assert(c == ' ');
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

// 2025-06-20
// Too slow
class Solution {
 public:
  int calculate(string s) {
    int cnt = 0;
    for (char c : s) {
      if (c != ' ') {
        s[cnt] = c;
        ++cnt;
      }
    }
    return eval(s.substr(0, cnt), 0, cnt);
  }

 private:
  int eval(const string& s, int begin, int end) {
    // cout << s << endl;
    vector<int> nums;
    for (int i = begin; i < end; ) {
      if (digit(s[i])) {
        // This will advance `i`
        nums.push_back(parseDigit(s, i));
      } else if (s[i] == '+' || s[i] == '-') {
        int mul = s[i] == '+' ? 1 : -1;
        ++i;
        if (digit(s[i])) {
          // This will advance `i`
          nums.push_back(mul * parseDigit(s, i));
        } else {
          assert(s[i] == '(');
          int j = findClose(s, i);          
          nums.push_back(mul * eval(s, i + 1, j));
          i = j + 1;
        }
      } else {
        int j = findClose(s, i);          
        nums.push_back(eval(s, i + 1, j));
        i = j + 1;
      }
    }
    return accumulate(nums.begin(), nums.end(), 0);
  }

  int parseDigit(const string& s, int& i) {
    int result = 0;
    while (i < s.size() && digit(s[i])) {
      result = 10 * result + (s[i] - '0');
      ++i;
    }
    return result;
  }

  bool digit(char c) {
    return '0' <= c && c <= '9';
  }

  int findClose(const string& s, int i) {
    assert(s[i] == '(');
    int j = i + 1;
    int balance = 1;
    for (; balance > 0; ++j) {
      if (s[j] == '(') {
        ++balance;
      } else if (s[j] == ')') {
        --balance;
      }
    }
    assert(s[j - 1] == ')');
    // j points to something after ')'
    // j - 1 points to ')'
    return j - 1;
  }
};

// Refer to https://discuss.leetcode.com/topic/15806/easy-18-lines-c-16-lines-python
// Date: 2016-09-27
// Comments:
// no longer correct -- 2025-06-20
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
// Comments:
// no longer correct -- 2025-06-20
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
  inline void eval(stack<int>& nums, stack<char>& signs) const {
    int op2 = nums.top();
    nums.pop();
    int op1 = nums.top();
    nums.pop();
    nums.push(signs.top() == '+'? op1 + op2 : op1 - op2);
    signs.pop();
  }

  inline void eval(stack<int>& nums, stack<char>& signs, char input)
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

  inline int eval(const string& s, int& idx) const {
    int num = 0;
    for ( ; idx < s.size() && s[idx] >= '0' && s[idx] <= '9'; ++idx)
      num = 10 * num + s[idx] - '0';
    return num;
  }
};
