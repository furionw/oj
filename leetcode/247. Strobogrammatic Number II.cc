// Copyright 2016 Qi Wang
// Date: 2016-12-29
// Method 2: refer to the Top Solutions
class Solution {
 public:
  vector<string> findStrobogrammatic(int n) {
    return helper(n, n);
  }

 private:
  vector<string> helper(int curN, int oriN) const {
    if (curN == 0) {
      return {""};
    } else if (curN == 1) {
      return {"0", "1", "8"};
    } else {
      auto subRes = helper(curN - 2, oriN);
      vector<string> res;
      for (auto& subElem : subRes) {
        res.push_back(string("1") + subElem + "1");
        res.push_back(string("8") + subElem + "8");
        res.push_back(string("6") + subElem + "9");
        res.push_back(string("9") + subElem + "6");
        // Make sure we do not construct the string with leading zero
        if (curN != oriN)
          res.push_back(string("0") + subElem + "0");
      }
      return res;
    }
  }
};

// Date: 2016-12-29
// Method 1
class Solution {
 public:
  vector<string> findStrobogrammatic(int n) {
    auto res = f(n);
    if (n > 1)
      res.resize(remove_if(res.begin(), res.end(), [](const string& s) {
        return s.front() == '0';  // leading zero, means invalid string
      }) - res.begin());
    return res;
  }

 private:
  vector<string> f(int n) const {
    if (n == 0) {
      return {""};
    } else if (n == 1) {
      return {"0", "1", "8"};
    } else {
      auto subRes = f(n - 2);
      vector<string> res;
      for (auto& subElem : subRes) {
        static constexpr char* STRS[] = {"0", "1", "8"};
        static constexpr char* STRS2[] = {"6", "9"};
        for (int i = 0; i < 3; ++i)
          res.push_back(STRS[i] + subElem + STRS[i]);
        for (int i = 0; i < 2; ++i)
          res.push_back(STRS2[i] + subElem + STRS2[1 - i]);
      }
      return res;
    }
  }
};

