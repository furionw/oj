// Date: 2022-10-17

// Method 2
// Just to note that there is a simpler solution in
// https://leetcode.com/problems/number-of-valid-clock-times/discuss/2706336/C%2B%2B-oror-Simple-and-Easy-to-Understand-Solution

// Method 1
class Solution {
 public:
  int countTime(string time) {
    int n1 = 0;
    for (int i = 0; i < 24; ++i) {
      n1 += valid(time.substr(0, 2), i, 24);
    }
    int n2 = 0;
    for (int i = 0; i < 60; ++i) {
      n2 += valid(time.substr(3, 2), i, 60);
    }
    return n1 * n2;
  }
  
 private:
   bool valid(const string& str, int v, int limit) {
     if (str[0] != '?' && str[0] != v / 10 + '0') {
       return false;
     }
     if (str[1] != '?' && str[1] != v % 10 + '0') {
       return false;
     }
     return v < limit;
   }
};
