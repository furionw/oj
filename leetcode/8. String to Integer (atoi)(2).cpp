class Solution {
 public:
  int myAtoi(string str) {
    int64_t res = 0;
    bool digit_begin = false;
    bool digit_end = false;
    bool positive = true;

    // Note that the if-conditions in the first level are all about characters
    // Thus we could use "else break" in the end
    for (size_t i = 0; i < str.size(); ++ i)
      // We have to use braces here to avoid the dangling else for '+' and '-'
      if (str[i] == ' ') {
        if (digit_begin) break;  // parse end
      } else if (str[i] == '+' || str[i] == '-')
        if (! digit_begin) {
          positive = (str[i]=='+')? positive: !positive;
          digit_begin = true;
        } else
          break;
      else if (str[i] >= '0' && str[i] <= '9') {
        digit_begin = true;
        res = 10 * res + (str[i] - '0');
        if (res > INT_MAX)  // That is, abs(res) >= INT_MIN
          return positive? INT_MAX: INT_MIN;
      } else
        break;  // parse end

    return positive? res: -res;
  }
};
