// Copyright 2017 Qi Wang
// Date: 2017-05-25
class Solution {
 public:
  bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3,
      vector<int>& p4) {
    return RightAngle(p1, p2, p3) && RightAngle(p1, p2, p4) &&
        RightAngle(p2, p3, p4);
  }
 
 private:
  bool RightAngle(const vector<int>& a, const vector<int>& b,
      const vector<int>& c) const {
    const int64_t ab = Dist(a, b), ac = Dist(a, c), bc = Dist(b, c);
    return 0 != ab && 0 != ac && 0 != bc && (
        (ab + ac == bc && ab == ac) || (ab + bc == ac && ab == bc) ||
        (ac + bc == ab && ac == bc)
    );
  }
 
  int64_t Dist(const vector<int>& a, const vector<int>& b) const {
    return pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2); 
  }
};
