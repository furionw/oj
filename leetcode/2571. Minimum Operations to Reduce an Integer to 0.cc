// 2025-06-22
class Solution {
 public:
  int minOperations(int n) {
    bitset<32> bits;
    for (int i = 0; i < 32; ++i) {
      bits[i] = n & 1;
      n >>= 1;
    }

    int result = 0;
    for (bool found = true; found;) {
      found = false;
      for (int i = 0; i < 20; ++i) {
        if (bits[i]) {
          bits[i] = false;
          ++result;

          if (!bits[i + 1]) {
            found = true;
            break;
          }

          for (++i; i < 20 && bits[i]; ++i) {
            bits[i] = false;
          }
          bits[i] = true;
          found = true;
          break;
        }
      }
    }

    return result;
  }
};
