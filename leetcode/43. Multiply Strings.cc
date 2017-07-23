// Copyright 2017 Qi Wang
// Date: 2017-07-22
class Solution {
 public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    int n = num1.size(), m = num2.size();
    vector<int> result(n + m, 0);
    for (int i = n - 1; i >= 0; --i) {
      for (int j = m - 1; j >= 0; --j) {
        result[n + m - i - j - 2] += (num1[i] - '0') * (num2[j] - '0');
      }
    }
    string str;
    for (int i = 0; i < result.size(); ++i) {
      if (i + 1 < result.size())
        result[i + 1] += result[i] / 10;
      str += result[i] % 10 + '0';
    }
    reverse(str.begin(), str.end());
    return str[0] == '0' ? str.substr(1) : str;
  }
};

class Solution 
{
public:
  string multiply(string a, string b) 
  {
    vector<int> result(a.size()+b.size(), 0);
    string ret;
    
    for (size_t i = 0; i < a.size(); ++ i)
    {
      for (size_t j = 0; j < b.size(); ++ j)
      {
          result[i+j+1] += ((a[i]-48)*(b[j]-48));
      }
    }
    for (int i=a.size()+b.size()-1; i >= 0; -- i)
    {
      if (i > 0)
      {
        result[i-1] += result[i] / 10; // carry
      }
      ret.insert(ret.begin(), result[i]%10+48);
    }
    ret = ret[0]=='0'? ret.substr(1): ret;

    return (a=="0"||b=="0")? "0": ret;
  }
};
