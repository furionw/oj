// Copyright 2016 Qi Wang
// Date: 2016-12-30
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    if (digits.empty()) return digits;
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; --i) {
      int sum = digits[i] + carry;
      digits[i] = sum % 10;
      carry = sum == 10;
    }
    if (carry)
      digits.insert(digits.begin(), 1);
    return digits;
  }
};

// Date: ...
class Solution 
{
public:
    vector<int> plusOne(vector<int> &digits) 
    {
      int carry = 1;
      vector<int> ret;

      for (int i = digits.size()-1; i >= 0; -- i)
      {
        ret.insert(ret.begin(), (digits[i]+carry)%10);
        carry = (digits[i] + carry) / 10;
      }
      if (carry != 0) // carry == 1
      {
        ret.insert(ret.begin(), 1);
      }

      return ret;
    }
};
