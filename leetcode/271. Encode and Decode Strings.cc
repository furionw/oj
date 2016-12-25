// Copyright 2016 Qi Wang
// Date: 2016-12-25
class Codec {
 public:
  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    return accumulate(strs.begin(), strs.end(), string(),
        [this](const string& pre, const string& str) {
          return pre + szToStr(str.size()) + str;
        });
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> res;
    for (size_t i = 0; i < s.size();) {
      res.push_back(s.substr(i + HEADER_SZ, strToSz(s.substr(i, HEADER_SZ))));
      i += HEADER_SZ + res.back().size();
    }
    return res;
  }

 private:
  // str[0, 1, …, 7] : str[0] is the most siginificant byte
  string szToStr(size_t sz) const {
    string str(HEADER_SZ, 0);
    for (int i = HEADER_SZ - 1; i >= 0; --i, sz >>= 8)
      str[i] = sz & UCHAR_MAX;
    return str;
  }

  size_t strToSz(const string& str) const {
    size_t sz = 0;
    for (size_t i = 0; i < HEADER_SZ; ++i)
      sz = (sz << 8) + static_cast<uint8_t>(str[i]);  // uint8_t !!!
    return sz;
  }

  static constexpr size_t HEADER_SZ = sizeof(size_t);
};
