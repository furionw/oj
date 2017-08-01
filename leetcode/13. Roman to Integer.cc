// Copyright 2017 Qi Wang
// Date: 2017-07-31
// Note that the solution on 2016-12-19 is more concise
class Solution {
 public:
  int romanToInt(string s) {
    pair<int, string> nums[] = {
      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
      {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    int result = 0;
    for (int i = 0, j = 0; i < s.size();) {
      for (; s.substr(i, nums[j].second.size()) != nums[j].second; ++j) {}
      while (s.substr(i, nums[j].second.size()) == nums[j].second) {
        result += nums[j].first;
        i += nums[j].second.size();
      }
    }
    return result;
  }
};

// Date: 2016-12-19
// Method 2: this method is faster than the method 1 using
//   - unordered_map<string, int> and s.substr
class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<char, int> rToI {
      {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
      {'X', 10}, {'V', 5}, {'I', 1}
    };
    int res = 0;
    for (size_t i = 0; i < s.size();) {
      if (i + 1 < s.size() && rToI[s[i]] < rToI[s[i + 1]]) {
        res += rToI[s[i + 1]] - rToI[s[i]];
        i += 2;
      } else {
        res += rToI[s[i++]];
      }
    }
    return res;
  }
};

// Date: 2016-12-19
// Method 1
class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<string, int> rToI {
      {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
      {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
      {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
    };
    int res = 0;
    for (size_t i = 0; i < s.size(); ) {
      if (rToI[s.substr(i, 1)] >= rToI[s.substr(i, 2)]) {
        res += rToI[s.substr(i++, 1)];
      } else {
        res += rToI[s.substr(i, 2)];
        i += 2;
      }
    }
    return res;
  }
};

// Date: 2014-06
class Solution {
 public:
  int romanToInt(string s) {
    int ret = 0;
    map<char, int> roman_to_int;
    roman_to_int['M'] = 1000;
    roman_to_int['D'] = 500;
    roman_to_int['C'] = 100;
    roman_to_int['L'] = 50;
    roman_to_int['X'] = 10;
    roman_to_int['V'] = 5;
    roman_to_int['I'] = 1;

    for (size_t i = 0; i < s.size(); ++ i)
    {
      if (i < s.size()-1 && roman_to_int[s[i]] < roman_to_int[s[i+1]])
      {
        ret = ret - roman_to_int[s[i]] + roman_to_int[s[i+1]];
        ++ i;
      } else
      {
        ret = ret + roman_to_int[s[i]];
      }
    }

    return ret;
  }
};
