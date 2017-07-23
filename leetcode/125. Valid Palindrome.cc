// Copyright 2017 Qi Wang
// Date: 2017-07-22
class Solution {
 public:
  bool isPalindrome(string s) {
    if (s.empty()) return true;
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
      for (; i < j && !Valid(s[i]); ++i) {}
      for (; i < j && !Valid(s[j]); --j) {}
      if (i >= j) break;
      if (Capitalize(s[i]) != Capitalize(s[j]))
        return false;
    }
    return true;
  }

 private:
  bool Valid(char c) const {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')
        || ('0' <= c && c <= '9');
  }

  char Capitalize(char c) const {
    return 'a' <= c && c <= 'z' ? c - 'a' + 'A' : c;
  }
};

class Solution 
{
public:
    bool isPalindrome(string s) 
    {
      string str(1, '/');
      for (size_t i = 0; i < s.size(); ++ i)
      {
        if (s[i]>='a' && s[i]<='z')
        {
          str.append(1, s[i]);
          str.append(1, '/');          
        } else if (s[i]>='A' && s[i]<='Z')
        {
          str.append(1, s[i]-'A'+'a');
          str.append(1, '/');
        } else if (s[i]>='0' && s[i]<='9')
        {
          str.append(1, s[i]);
          str.append(1, '/');
        }
      }
      int mid = str.size() / 2;
      for (int i = 1; mid-i>=0 && mid+i<str.size(); ++ i)
      {
        if (str[mid-i] != str[mid+i])
        {
          return false;
        }
      }
      return true;
    }
};