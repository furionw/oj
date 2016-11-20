// Copyright 2016 Qi Wang
// Date: 2016-11-20
inline string generate(const string& gene, int i) {
  return gene.substr(0, i - 1) + "*" + gene.substr(i);
}

template<int TIMES>
struct loop {
  static inline void f(const string& gene,
      map<string, list<string>>& mutationTbl) {
    loop<TIMES - 1>::f(gene, mutationTbl);
    mutationTbl[generate(gene, TIMES)].push_back(gene);
  }
};

template<>
struct loop<0> {
  static inline void f(const string& gene,
      map<string, list<string>>& mutationTbl) {}
};

class Solution {
 public:
  int minMutation(string start, string end, vector<string>& bank) {
    map<string, list<string>> mutationTbl;
    for (auto& gene : bank)
      loop<8>::f(gene, mutationTbl);
    queue<pair<string, int>> q;
    set<string> vi;
    q.emplace(start, 0);
    while (!q.empty()) {
      string gene = q.front().first;
      int dis = q.front().second;
      q.pop();
      // The range is [1, 8], instead of [0, 8)
      for (int i = 1; i <= 8; ++i) {
        auto pattern = generate(gene, i);
        for (auto& nextGene : mutationTbl[pattern]) {
          if (nextGene == end) return dis + 1;
          if (vi.find(nextGene) == vi.end()) {
            vi.insert(nextGene);
            q.emplace(nextGene, dis + 1);
          }
        }
      }
    }
    return -1;
  }
};
