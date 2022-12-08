// Date: 2022-12-07
// Method 2
// Refer to: https://leetcode.com/problems/determine-if-two-events-have-conflict/solutions/2734120/java-c-python-easy-1-liner-solutions/
class Solution {
 public:
  bool haveConflict(vector<string>& event1, vector<string>& event2) {
    return event2[1] >= event1[0] && event1[1] >= event2[0];
  }
};

// Method 1
class Solution {
 public:
  bool haveConflict(vector<string>& event1, vector<string>& event2) {
    int l1 = timeToInt(event1[0]), r1 = timeToInt(event1[1]);
    int l2 = timeToInt(event2[0]), r2 = timeToInt(event2[1]);
    return (l2 <= l1 && l1 <= r2) || (l2 <= r1 && r1 <= r2)
        || (l1 <= l2 && l2 <= r1) || (l1 <= r2 && r2 <= r1);
  }

 private:
  int timeToInt(const string& s) {
    return 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3));
  }
};
