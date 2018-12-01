#include <iostream>
#include <algorithm>
#include <vector>
#include <initializer_list>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <climits>

using namespace std;

// Copyright 2017 Qi Wang
// Date: 2017-06-05
class Solution {
 public:
  bool isValid(string code) {
    auto p = code.c_str();
    return ClosedTag(p) && 0 == *p;
  }
 
 private:
  bool ClosedTag(const char*& p) const {
    auto q = p;
    if ('<' != *q++) return false;
    string tag;
    while (0 != *q && isupper(*q)) tag += *q++;
    if (tag.size() < 1 || tag.size() > 9) return false;
    if ('>' != *q++) return false;
    Content(q);
    if ('<' != *q++) return false;
    if ('/' != *q++) return false;
    // not equal
    if (strncmp(q, tag.c_str(), tag.size())) {
      return false;
    // equal
    } else {
      q += tag.size();
    }
    if ('>' != *q++) return false;
    p = q;
    return true;
  }
 
  void Content(const char*& p) const {
    while (0 != *p) {
      if ('<' != *p) {
        ++p;
      } else if (!CData(p) && !ClosedTag(p)) {
        break;
      }
    }
  }
 
  bool CData(const char*& p) const {
    auto q = p;
    const char* prefix = "<![CDATA[";
    if (strncmp(q, prefix, strlen(prefix))) {
      return false;
    } else {
      q += strlen(prefix);
    }
    q = strstr(q, "]]>");
    if (nullptr == q) {
      return false;
    } else {
      p = q + 3;
      return true;
    }
  }
};

int main() {
  map<string, bool> test{
    {"<DIV>This is the first line <![CDATA[<div>]]></DIV>", true},
    {"<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>", true},
    {"<A>  <B> </A>   </B>", false},
    {"<DIV>  div tag is not closed  <DIV>", false},
    {"<DIV>  unmatched <  </DIV>", false},
    {"<DIV> closed tags with invalid tag name  <b>123</b> </DIV>", false},
    {"<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>", false},
    {"<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>", false},
    {"<![CDATA[wahaha]]]><![CDATA[]> wahaha]]>", false},
    {"<A><A>/A></A></A>", true},
    {"<A><A>456</A>  <A> 123  !!  <![CDATA[]]>  123 </A>   <A>123</A></A>", true},
    {"<A><A>456</A>  <A> 123  !!  <![CDATA[<![cdata]>]]>  123 </A>   <A><![CDATA[</A>]]>  </A>  <A>123</A></A>", true},
    {"<A></A><B></B>", false},
  };
  for (const auto& elem : test) {
    if (Solution().isValid(elem.first) != elem.second)
      cout << elem.first << ", " << elem.second << endl;
  }
}
