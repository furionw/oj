// Date: 2022-11-07
// Method 2: refer to https://leetcode.com/problems/score-of-parentheses/discuss/141777/C%2B%2BJavaPython-O(1)-Space
class Solution {
 public:
  int scoreOfParentheses(string s) {
    int res = 0;
    int cnt = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        ++cnt;
      } else {
        --cnt;
      }
      if (s[i] == ')' && s[i - 1] == '(') {
        res += 1 << cnt;
      }
    }
    return res;
  }
};

// Method 1
class Solution {
 public:
  int scoreOfParentheses(string s) {
    return scoreOfParentheses(s, 0, s.size());
  }

 private:
  int scoreOfParentheses(const string& s, size_t begin, size_t end) {
    int cnt = 0;
    int res = 0;
    for (size_t i = begin, prev = begin; i < end; ++i) {
      if (s[i] == '(') {
        ++cnt;
      } else if (--cnt == 0) {
        res += prev + 1 == i
            ? 1
            : 2 * scoreOfParentheses(s, prev + 1, i);
        prev = i + 1;
      }
    }
    return res;
  }
};
