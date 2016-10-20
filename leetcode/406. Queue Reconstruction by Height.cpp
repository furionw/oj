// Copyright 2016 Qi Wang
// Date: 2016-10-05
struct People {
  People(int h, int k): height(h), curK(k), originK(k) {}
  int height;
  int curK;
  int originK;
};

class Solution {
 public:
  // (h, k)
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    // init
    vector<People> p;
    for (auto& elem: people)
      p.emplace_back(elem.first, elem.second);
    vector<pair<int, int>> res;
    // calculate
    while (!p.empty()) {
      auto font = removeShortestManWithZeroK(p);
      updateQ(p, font.first);
      res.push_back(font);
    }
    return res;
  }

 private:
  inline pair<int, int> removeShortestManWithZeroK(vector<People>& people)
      const {
    pair<int, int> res(INT_MAX, 0);
    vector<People>::iterator resIt = &res;  // used for removing element before returning it
    for (auto it = people.begin(); it != people.end(); ++it)
      if (it->curK == 0 && it->height < res.first) {
        res.first = it->height;
        res.second = it->originK;
        resIt = it;
      }
    people.erase(resIt);
    return res;
  }

  inline void updateQ(vector<People>& people, int h) const {
    for (auto &elem : people) {
      if (elem.height <= h) {
        assert(elem.curK > 0);
        --elem.curK;
      }
    }
  }
};
