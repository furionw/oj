// 2025-08-08
class Solution {
 public:
  int superPow(int a, vector<int>& b) {
    a %= kMod;
    return superPow(a, b, 0);
  }

 private:
  int superPow(int a, vector<int>& b, int i) {
    if (i + 1 == b.size()) {
      int result = 1;
      for (int j = 0; j < b[i]; ++j) {
        result = result * a % kMod;
      }
      return result;
    }
    bool remainder = false;
    for (int j = i; j < b.size(); ++j) {
      int num = 10 * remainder + b[j];
      b[j] = num / 2;
      remainder = num % 2;
    }
    int sub = superPow(a, b, b[i] ? i : i + 1);
    sub = (sub * sub) % kMod;
    if (remainder) {
      sub = sub * a % kMod;
    }
    return sub;
  }

 private:
  static constexpr int kMod = 1337;
};
