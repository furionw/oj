// Copyright 2017 Qi Wang
// Date: 2017-06-05
// Refer to watashi's solution
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
