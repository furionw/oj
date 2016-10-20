// Copyright 2016 Qi Wang
// Time complexity O(n)
// Reference: http://www.cnblogs.com/CarryPotMan/p/5384172.html
// Date: 2016-10-09
class Solution {
 public:
  string removeKdigits(string num, int k) {
    if (num.size() == k) return "0";
    vector<int> nums;
    for (size_t i = 0; i < num.size(); ++i) {
      while (!nums.empty() && k > 0 && nums.back() > num[i]) {
        --k;
        nums.pop_back();
      }
      if (!nums.empty() || num[i] != '0') nums.push_back(num[i]);
    }
    string res(nums.begin(), nums.end() - k);
    return res != "" ? res : "0";
  }
};

// Time complexity O(nk)
// Date: 2016-10-09
class Solution {
 public:
  string removeKdigits(string num, int k) {
    if (num.size() == k) return "0";
    while (k != 0) {
      int preK = k;
      tryToRemoveOneCharacter(num, k);
      if (preK == k) break;
    }
    num = num.substr(0, num.size() - k);    
    return num != "" ? num : "0";
  }

 private:
  inline void tryToRemoveOneCharacter(string& num, int& k) const {
    if (num.empty()) return;
    for (size_t idx = 0; idx < num.size() - 1; ++idx)
      if (num[idx] > num[idx + 1]) {
        --k;
        if (idx != 0) {
          num = num.substr(0, idx) + num.substr(idx + 1);
        } else {
          // handle the preceding 0s
          for (++idx; idx < num.size(); ++idx)
            if (num[idx] != '0') break;
          num = num.substr(idx);
        }
        return;
      }
  }
};
