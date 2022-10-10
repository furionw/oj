// Date: 2022-10-09
class Solution {
 public:
  int minimizeXor(int num1, int num2) {
    int bits = countBits(num2);
    vector<bool> place(31, false);
    for (int i = 30; i >= 0 && bits > 0; --i) {
      int mask = 1 << i;
      if (num1 & mask) {
        place[i] = true;
        --bits;
      }
    }
    
    for (int i = 0; i < place.size() && bits > 0; ++i) {
      if (!place[i]) {
        place[i] = true;
        --bits;
      }
    }
    
    int result = 0;
    for (int i = 0; i < place.size(); ++i) {
      if (place[i]) {
        result += 1 << i;
      }
    }
    return result;
  }

 private:
  int countBits(int num) {
    int result = 0;
    for (; num != 0; num >>= 1) {
      result += num & 1;
    }
    return result;
  }
};
