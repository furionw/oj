// Date: 2022-10-11
class Solution {
 public:
  int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    unordered_map<char, int> cntByType;
    unordered_map<char, int> lastIdxByType;
    for (int i = garbage.size() - 1; i >= 0; --i) {
      for (char t : garbage[i]) {
        ++cntByType[t];
        lastIdxByType[t] = max(lastIdxByType[t], int(i));
      }
    }    
    auto cal = [&cntByType, &lastIdxByType, &travel](char t) {
      if (cntByType[t] == 0) {
        return 0;
      }
      return cntByType[t] +
          accumulate(travel.begin(), travel.begin() + lastIdxByType[t], 0,
              [](int acc, int cost) { return acc + cost; });
    };
    return cal('M') + cal('P') + cal('G');
  }
};
