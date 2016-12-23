// Copyright 2016 Qi Wang
// Date: 2016-12-23
class Solution {
 public:
  bool isStrobogrammatic(string num) {
    if (num.size() & 1 && !is018(num[num.size() >> 1])) return false;
    size_t mid = num.size() >> 1;
    for (size_t i = 0; i < mid; ++i)
      // return false directly if the pair doesn't fall into any of this case
      if (!((is018(num[i]) && num[i] == num[num.size() - 1 - i])
          || (num[i] == '6' && num[num.size() - 1 - i] == '9')
          || (num[i] == '9' && num[num.size() - 1 - i] == '6')))
        return false;
    return true;
  }

 private:
  bool is018(char c) const { return c == '0' || c == '1' || c == '8'; }
};
