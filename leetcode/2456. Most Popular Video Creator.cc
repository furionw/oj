// Date: 2022-10-31
struct Video {
  string id;
  int v;
  
  Video() {}
  Video(const string& id, int v) : id(id), v(v) {}
  
  bool operator<(const Video& other) const {
    return v != other.v
        ? v < other.v
        : id > other.id;
  }
};

class Solution {
 public:
  vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
    unordered_map<string, priority_queue<Video>> videosByCreator;
    unordered_map<string, size_t> popularityByCreator;
    for (size_t i = 0; i < views.size(); ++i) {
      string c = creators[i];
      popularityByCreator[c] += views[i];
      videosByCreator[c].emplace(ids[i], views[i]);
    }
    size_t highestP = 0;
    for (const auto& [_, p] : popularityByCreator) {
      highestP = max(highestP, p);
    }
    vector<vector<string>> res;
    for (const auto& [c, videos] : videosByCreator) {
      if (popularityByCreator[c] != highestP) {
        continue;
      }
      vector<string> elem {c, videos.top().id};
      res.push_back(elem);
    }
    return res;
  }
};
