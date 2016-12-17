// Copyright 2016 Qi Wang
// Date: 2016-12-17
class Solution {
 public:
  string validIPAddress(string IP) {
    return any_of(IP.begin(), IP.end(), [](char c) { return c == '.'; })
        ? validIPv4(IP) : validIPv6(IP);
  }

 private:
  string validIPv4(const string& ip) const {
    size_t pos = 0;
    for (int seg = 0; seg < 4; ++seg) {
      size_t next = ip.find('.', pos);
      string str = ip.substr(pos, next - pos);
      if (str.empty() || str.size() > 3 || !isDec(str) || stoi(str) > 255
          || (str.size() > 1 && str[0] == '0')) return NEITHER;
      pos = next + 1;
    }
    // pos = string::npos + 1 == 0
    return pos == 0 ? "IPv4" : NEITHER;
  }

  string validIPv6(const string& ip) const {
    size_t pos = 0;
    for (int seg = 0; seg < 16; ++seg) {
      size_t next = ip.find(':', pos);
      string str = ip.substr(pos, next - pos);
      if (str.empty() || str.size() > 4 || !isHex(str)) return NEITHER;
      pos = next + 1;
    }
    return pos == 0 ? "IPv6" : NEITHER;
  }
  
  bool isDigit(char c) const { return '0' <= c && c <= '9'; }

  bool isDec(const string& str) const {
    return all_of(str.begin(), str.end(), [this](char c) {
      return isDigit(c);
    });
  }

  bool isHex(const string& str) const {
    return all_of(str.begin(), str.end(), [this](char c) {
      return isDigit(c) || ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F');
    });
  }

  // compile error will be caused if we use:
  //   - static constexpr char[] NEITHER = "..." here
  const string NEITHER = "Neither";
};
