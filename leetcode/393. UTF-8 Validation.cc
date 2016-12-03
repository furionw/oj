// Copyright 2016 Qi Wang
// Date: 2016-12-03
class Solution {
 public:
  bool validUtf8(vector<int>& data) {
    for (size_t i = 0; i < data.size(); ++i) {
      int cnt = countBytes(static_cast<uint8_t>(data[i]));
      // Illegal head
      if (cnt == -1) {
        return false;
      } else if (cnt > 1) {
        if (i + cnt - 1 >= data.size()) return false;
        while (--cnt)
          if (!validateTailByte(static_cast<uint8_t>(data[++i])))
            return false;
      }
    }
    return true;
  }

 private:
  inline int countBytes(uint8_t byte) const {
    static constexpr uint8_t MASK = 1 << 7;
    if (!(byte & MASK)) {
      return 1;
    } else {
      int res = 0;
      for (; byte & MASK; byte <<= 1) ++res;
      return res >= 2 && res <= 4 ? res : -1;
    }
  }

  inline bool validateTailByte(uint8_t byte) const {
    static constexpr uint8_t MASK = 3 << 6;
    static constexpr uint8_t VALID_HEAD = 1 << 7;
    return (byte & MASK) == VALID_HEAD;
  }
};
