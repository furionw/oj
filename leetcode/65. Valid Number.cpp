// Copyright 2016 Stephen Wong
// DFA
// Date: 2016-09-25
class Solution {
 public:
  bool isNumber(string s) {
    vector<map<char, int>> DFA = {
      {},
      {{BLANK, 1}, {SIGN, 2}, {DIGIT, 3}, {FP, 4}},  // state 1
      {{DIGIT, 3}, {FP, 4}},  // state 2
      {{DIGIT, 3}, {FP, 5}, {E, 6}, {BLANK, 9}},  // state 3
      {{DIGIT, 5}},  // state 4
      {{DIGIT, 5}, {E, 6}, {BLANK, 9}},  // state 5
      {{SIGN, 7}, {DIGIT, 8}},  // 6
      {{DIGIT, 8}},  // 7
      {{DIGIT, 8}, {BLANK, 9}},  // 8
      {{BLANK, 9}}  // 9
    };
    int q = 1;
    for (size_t i = 0; i < s.size(); ++i) {
      char a = parseInput(s[i]);
      if (DFA[q].find(a) == DFA[q].end()) return false;
      q = DFA[q][a];
    }
    return q == 3 || q == 5 || q == 8 || q == 9;
  }

 private:
  inline char parseInput(char c) const {
    if (c == '+' || c == '-') {
      return SIGN;
    } else if (c >= '0' && c <= '9') {
      return DIGIT;
    } else {
      return c;
    }
  }

  const char DIGIT = 'd', SIGN = 's', E = 'e', BLANK = ' ', FP = '.';
};


Date: 2014-07-25
#include <string>
using namespace std;

class Solution 
{
public:
    bool isNumber(const char *s) 
    {
        string str;
        size_t pos = string::npos;
        bool begin_space=true, number_finish=false;

        // 去掉前导后导空格
        for (int i = 0; i < strlen(s); ++ i)
        {
          if (s[i] == ' ')
          {
            if (begin_space == true)
            {
              continue;
            } else
            {
              number_finish = true;
            }
          } else if(number_finish == false) // s[i]!=' '
          {
            begin_space = false;
            str.push_back(s[i]);
          } else
          {
            return false;
          }
        }
        // 判断是否有非法字符，同时寻找e，注意到第二次找到e将返回false
        for (size_t i = 0; i < str.size(); ++ i)
        {
          if (str[i]=='e' && pos==string::npos)
          {
            pos = i;
          } else if (str[i]!='-' && str[i]!='+' && str[i]!='.'
            && (str[i]<'0'||str[i]>'9'))
          {
            return false;
          } 
        }

        if (pos==str.size()-1) // last character is 'e'
        {
          return false;
        } else if (pos == string::npos) // no 'e'
        {
          return gao(str, 1);
        } else
        {
          return gao(str.substr(0, pos), 1) && gao(str.substr(pos+1), 0);
        }
    }
private:
  bool gao(const string& str, int dot_available)
  {
    int dot_cnt = 0;
    bool has_digit=false;
    for (int i = 0; i <str.size(); ++ i)
    {
      dot_cnt = str[i]=='.'? dot_cnt+1: dot_cnt;
      if (i!=0 && (str[i]=='+'||str[i]=='-'))
      {
        return false;
      } else if (str[i]>='0' && str[i]<='9')
      {
        has_digit = true;
      }
    }
    return dot_cnt<=dot_available && has_digit;
  }
};

int main()
{
  Solution a;
  a.isNumber("6e6.5");
  return 0;
}