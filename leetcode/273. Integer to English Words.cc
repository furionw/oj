// Copyright 2017 Qi Wang
// Date: 2017-07-20
// Please note that the solution on 2017-03-05 is much more concise.
class Solution {
 public:
  string numberToWords(int num) {
    if (num == 0) return "Zero";
    string result;
    for (int i = 0; num > 0; num /= 1000, ++i) {
      int n = num % 1000;
      if (n == 0) continue;
      string temp;
      if (n >= 100) {
        temp += one_digit[n / 100 - 1] + " Hundred";
        n %= 100;
      }
      if (n != 0 && !temp.empty()) {
        temp += " ";
      }
      if (n < 10) {
        if (n != 0)
          temp += one_digit[n - 1];
      } else if (n < 20) {
        temp += ten_plus[n - 10];
      } else {
        temp += two_digits[n / 10 - 2];
        n %= 10;
        if (n > 0) {
          temp += " ";
          temp += one_digit[n - 1];
        }
      }
      result = temp + suffixes[i] + (result.empty() ? "" : " ") + result;
    }
    return result;
  }

 private:
  string one_digit[9] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven",
      "Eight", "Nine"};

  string ten_plus[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
      "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  
  string two_digits[8] = {"Twenty", "Thirty", "Forty", "Fifty",
      "Sixty", "Seventy", "Eighty", "Ninety"};

  string suffixes[4] = {"", " Thousand", " Million", " Billion"};
};

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
