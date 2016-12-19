// Copyright 2016 Qi Wang
// Date: 2016-12-19
class Solution {
 public:
  string intToRoman(int num) {
    vector<pair<int, string>> iToR {
      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CV"},
      {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
      {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    string res;
    for (auto& p : iToR)
      for (; num >= p.first; num -= p.first)
        res += p.second;
    return res;
  }
};

// Date: 2014-06
class Solution 
{
public:
    string intToRoman(int num) 
    {
      int digit[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
      string str[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
      string ret;

      for (int i = 0; i < sizeof(digit)/sizeof(int); ++ i)
      {
        while (num >= digit[i])
        {
          num -= digit[i];
          ret += str[i];
        }
      }

      return ret;
    }
};
