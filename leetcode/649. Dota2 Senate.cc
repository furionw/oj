// Copyright 2017 Qi Wang
// Date: 2017-07-29
class Solution {
 public:
  string predictPartyVictory(string senate) {
    list<char> senates(senate.begin(), senate.end());
    list<list<char>::iterator> radiant, dire;
    int flag = 0;
    while (true) {
      list<char> prev_senates = move(senates);
      radiant.clear();
      dire.clear();
      for (char s : prev_senates) {
        if (s == 'R') {
          if (flag >= 0) {
            radiant.push_back(senates.emplace(senates.end(), s));
          }
          ++flag;
        // c == 'D'
        } else {
          if (flag <= 0) {
            dire.push_back(senates.emplace(senates.end(), s));
          }
          --flag;
        }
      }
      for (; flag > 0 && !dire.empty(); --flag) {
        senates.erase(dire.front());
        dire.pop_front();
      }
      for (; flag < 0 && !radiant.empty(); ++flag) {
        senates.erase(radiant.front());
        radiant.pop_front();
      }
      if (dire.empty()) {
        return "Radiant";
      } else if (radiant.empty()) {
        return "Dire";
      }
    }
    return "";
  }
};