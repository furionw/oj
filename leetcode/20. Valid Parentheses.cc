// Copyright 2017 Qi Wang
// Date: 2017-07-03
class Solution {
 public:
  bool isValid(string s) {
    stack<char> stk;
    for (char c : s) {
      if ('{' == c || '[' == c || '(' == c) {
        stk.push(c);
      } else if (!stk.empty() && (('}' == c && stk.top() == '{')
          || (']' == c && stk.top() == '[') || (')' == c && stk.top() == '(')
      )) {
        stk.pop();
      } else {
        return false;
      }
    }
    return stk.empty();
  }
};

// Date: 2016-12-21
class Solution {
 public:
  bool isValid(string s) {
    stack<char> cStack;
    for (char c : s) {
      switch(c) {
        case '(':
        case '{':
        case '[':
          cStack.push(c);
          break;
        case ')':
          if (cStack.empty() || cStack.top() != '(') return false;
          cStack.pop();
          break;
        case '}':
          if (cStack.empty() || cStack.top() != '{') return false;
          cStack.pop();
          break;
        case ']':
          if (cStack.empty() || cStack.top() != '[') return false;
          cStack.pop();
          break;
        default:
          cerr << "Illegal input\n";
      }
    }
    return cStack.empty();
  }
};

// Date: 2014-06
class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> ss;

        for (auto it = s.begin(); it != s.end(); ++ it)
        {
            if (*it=='(' || *it=='[' || *it=='{')
            {
                ss.push(*it);
            } else if ((ss.empty()==false)
              && ((*it==')'&&ss.top()=='(') || (*it==']'&&ss.top()=='[') || (*it=='}'&&ss.top()=='{')))
            {
                ss.pop();
            } else 
            {
                return false;
            }
        }

        return ss.empty();
    }
};