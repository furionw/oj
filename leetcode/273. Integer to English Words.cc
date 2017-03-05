// Copyright 2017 Qi Wang
// Date: 2017-03-05
class Solution {
 public:
  string numberToWords(int num) {
    if (num == 0) return "Zero";
    vector<string> token;
    for (int i = 0; i <= 3 && num != 0; ++i, num /= 1000)
      if (num % 1000 != 0)
        token.insert(token.begin(), F(num % 1000) + POSTFIX[i]);
    string result;
    for (string& str : token) result += string(" ") + move(str);
    return result.substr(1);
  }

 private:
  string F(int num) const {
    string result;
    if (num < 20) {
      result = DIGITS[num];
    } else if (num < 100) {
      result = TWO_DIGITS[num / 10];
      if (num % 10 != 0) result += string(" ") + DIGITS[num % 10];
    } else {
      result = DIGITS[num / 100] + " Hundred";
      if (num % 100 != 0) result += string(" ") + F(num % 100);
    }
    return result;
  }

  vector<string> DIGITS = {"Zero", "One", "Two", "Three", "Four",
      "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
      "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
      "Nineteen"};
  vector<string> TWO_DIGITS = {"", "", "Twenty", "Thirty", "Forty",
      "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
  vector<string> POSTFIX = {"", " Thousand", " Million", " Billion"};
};
