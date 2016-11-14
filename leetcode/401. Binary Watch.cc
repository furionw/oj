// Copyright 2016 Qi Wang
// Refer to: http://bookshadow.com/weblog/2016/09/18/leetcode-binary-watch/
// Method 2
class Solution {
 public:
  vector<string> readBinaryWatch(int num) {
    vector<string> res;
    for (int hr = 0; hr < 12; ++hr)
      for (int min = 0; min < 60; ++min)
        if (bitset<4>(hr).count() + bitset<6>(min).count() == num)
          res.push_back(to_string(hr) + ":" + (min < 10 ? "0" : string())
              + to_string(min));
    return res;
  }
};

// Method 1
// Date: 2016-11-14
class Solution {
 public:
  vector<string> readBinaryWatch(int num) {
    vector<string> res;
    for (int i = 0; i <= num; ++i) {
      vector<int> hrs, mins;
      vector<bool> hrBits(4, false), minBits(6, false);
      recursive(hrBits, 0, i, 11, hrs);
      recursive(minBits, 0, num - i, 59, mins);
      for (int hr : hrs)
        for (int min : mins)
          res.push_back(to_string(hr) + ":" + 
            (min < 10 ? "0" : string()) + to_string(min));
    }
    return res;
  }

 private:
  void recursive(vector<bool> bits, size_t cur, int remain, int max, vector<int>& vtOut) {
    if (cur == bits.size()) {
      if (remain == 0) {
        int res = 0;
        for (size_t i = 0; i < bits.size(); ++i)
          res += (bits[i] ? 1 : 0) << i;
        if (res <= max) vtOut.push_back(res);
      }
    } else {
      recursive(bits, cur + 1, remain, max, vtOut);
      bits[cur] = true;
      recursive(bits, cur + 1, remain - 1, max, vtOut);
    }
  }
};
