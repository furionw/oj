// Copyright 2017 Qi Wang
// Date: 2017-11-07
class Solution {
 public:
  bool isPalindrome(string s) {
    if (s.empty()) return true;
    int l = 0, r = s.size() - 1;
    while (l < r) {
      for (; l < r && !IsAlphaNumeric(&s[l]); ++l) {}
      for (; l < r && !IsAlphaNumeric(&s[r]); --r) {}
      if (s[l++] != s[r--]) return false;
    }
    return true;
  }
 
 private:
  bool IsAlphaNumeric(char* c) const {
    if ('A' <= *c && *c <= 'Z') {
      *c += 'a' - 'A';
      return true;
    } else {
      return ('0' <= *c && *c <= '9') || ('a' <= *c && *c <= 'z');
    }
  }
};

// Date: 2017-08-31
class Solution {
 public:
  bool isPalindrome(string s) {
    if (s.empty()) return true;
    int i = 0, j = s.size() - 1;
    while (i < j) {
      if (!Alphanumberic(&s[i])) {
        ++i;
      } else if (!Alphanumberic(&s[j])) {
        --j;
      } else if (s[i] != s[j]) {
        return false;
      } else {
        ++i, --j;
      }
    }
    return true;
  }

 private:
  bool Alphanumberic(char* c) {
    if ('A' <= *c && *c <= 'Z') {
      *c = *c + 'a' - 'A';
      return true;
    }
    return ('0' <= *c && *c <= '9') || ('a' <= *c && *c <= 'z');
  }
};


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