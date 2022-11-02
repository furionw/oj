// Date: 2022-11-01
class Solution {
 public:
  string oddString(vector<string>& words) {
    for (size_t j = 1; j < words[0].size(); ++j) {
      unordered_map<int, list<size_t>> idxsByFreq;
      for (size_t i = 0; i < words.size(); ++i) {
        idxsByFreq[words[i][j] - words[i][j - 1]].push_back(i);
      }
      if (idxsByFreq.size() > 1) {
        return idxsByFreq.begin()->second.size() == 1
            ? words[idxsByFreq.begin()->second.front()]
            : words[(++idxsByFreq.begin())->second.front()];
      }
    }
    return "";  // comfor compiler
  }
};
