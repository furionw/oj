// Copyright 2017 Qi Wang
// Date: 2017-08-27
class Solution {
 public:
  void reverseWords(string &s) {
    Trim(&s);
    if (s.empty()) return;
    reverse(s.begin(), s.end());
    int begin = 0;
    while (true) {
      int end = s.find_first_of(' ', begin);
      if (end != string::npos) {
        Reverse(&s, begin, end - 1);
        begin = end + 1;
      } else {
        Reverse(&s, begin, s.size() - 1);
        break;
      }
    }
  }
 
 private:
  void Trim(string* s) const {
    int len = 0;
    for (int i = 0; i < s->size(); ++i) {
      if ((*s)[i] == ' ') {
        if (len != 0 && (*s)[len - 1] != ' ') {
          (*s)[len++] = (*s)[i];
        }
      } else {
        (*s)[len++] = (*s)[i];
      }
    }
    len -= len > 0 && (*s)[len - 1] == ' ';
    s->resize(len);
  }
 
  void Reverse(string* s, int begin, int end) const {
    while (begin < end) {
      swap((*s)[begin++], (*s)[end--]);
    }
  }
};

void reverseWords(string &s) 
{
  string s2;
  bool first = true;

  for (size_t i = 0; i < s.size(); ++ i)
  {
    int begin, end;
    for ( ; i < s.size() && s[i] == ' '; ++ i ) {}
    begin = i;
    for ( ; i < s.size() && s[i] != ' '; ++ i) {}
    end = i;
    if (begin == s.size())
    {
      break;
    }
    if (first == true)
    {
      s2.insert(0, s.substr(begin, end-begin));
      first =  false;
    } else
    {
      s2.insert(0, " ");
      s2.insert(0, s.substr(begin, end-begin));
    }
  }

  s = s2;
}
