// Copyright 2017 Qi Wang
// Date: 2017-01-02
// Method 3: refer to https://discuss.leetcode.com/topic/60394/easy-concept-with-python-c-java-solution
class Solution {
 private:
  using P = pair<int, int>;
  using VP = vector<P>;

 public:
  VP reconstructQueue(VP& people) {
    sort(people.begin(), people.end(), [](const P& lhs, const P& rhs) {
      return lhs.first != rhs.first
          ? lhs.first > rhs.first : lhs.second < rhs.second;
    });
    VP res;
    for (auto& p : people)
      res.insert(res.begin() + p.second, p);
    return res;
  }
};

// Date: 2017-01-02
// Method 2: refer to https://discuss.leetcode.com/topic/60394/easy-concept-with-python-c-java-solution
class Solution {
 private:
  using P = pair<int, int>;
  using VP = vector<P>;

 public:
  VP reconstructQueue(VP& people) {
    sort(people.begin(), people.end(), [](const P& lhs, const P& rhs) {
      return lhs.first != rhs.first
          ? lhs.first > rhs.first : lhs.second < rhs.second;
    });
    VP res;
    for (auto& en_q : people) {
      auto it = res.begin();
      int k = en_q.second;
      for (; k; ++it)
        if (it->first >= en_q.first) --k;
      res.insert(it, en_q);
    }
    return res;
  }
};

// Date: 2017-01-02
// Method 1
class Solution {
 private:
  struct People {
    People(const pair<int, int>& p)
        : height(p.first), cur_k(p.second), origin_k(p.second) {}
    operator pair<int, int>() const { return {height, origin_k}; }
    int height, cur_k, origin_k;
  };

 public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    vector<pair<int ,int>> res;
    list<People> ppl(people.begin(), people.end());
    while (!ppl.empty())
      res.emplace_back(rm_shortest_man_with_0k(ppl));
    return res;
  }

 private:
  People rm_shortest_man_with_0k(list<People>& ppl) const {
    int height = INT_MAX;
    list<People>::iterator rmIt;
    for (auto it = ppl.begin(); it != ppl.end(); ++it)
      if (it->cur_k == 0 && it->height < height) {
        rmIt = it;
        height = it->height;
      }
    People res = *rmIt;
    ppl.erase(rmIt);
    // update the remaining people's cur_k value
    for (auto& p : ppl)
      p.cur_k -= p.height <= res.height;
    return res;
  }
};

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
