// 2025-05-27
class Solution {
 public:
  vector<string> removeSubfolders(vector<string>& folder) {
    sort(folder.begin(), folder.end());
    vector<string> result;
    for (int i = 0; i < folder.size(); ++i) {
      result.push_back(std::move(folder[i]));
      auto prefix = result.back() + '/';
      for (; i + 1 < folder.size() 
          && folder[i + 1].substr(0, prefix.size()) == prefix; ++i) {}
    }
    return result;
  }
};
