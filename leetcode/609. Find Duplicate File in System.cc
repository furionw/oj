// Copyright 2017 Qi Wang
// Date: 2017-06-04
class Solution {
 public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> record;
    for (const auto& path : paths) {
      size_t space = path.find(' ');  // white space
      string dir = path.substr(0, space);
      while (space < path.size()) {
        size_t b1 = path.find('(', space), b2 = path.find(')', space);
        record[path.substr(b1 + 1, b2 - b1 - 1)]
            .push_back(dir + '/' + path.substr(space + 1, b1 - space - 1));
        space = b2 + 1;
      }
    }
    vector<vector<string>> result;
    for (auto& elem : record)
      if (elem.second.size() > 1)
        result.emplace_back(move(elem.second));
    return result;
  }
};
