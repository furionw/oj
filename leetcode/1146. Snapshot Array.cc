// 2025-07-25
class SnapshotArray {
 public:
  SnapshotArray(int length) {}
    
  void set(int index, int val) {
    auto& snaps = nums_[index];
    if (snaps.empty() || snaps.back().first < snapId_) {
      snaps.emplace_back(snapId_, val);
    } else {
      snaps.back().second = val;
    }
  }
    
  int snap() {
    return snapId_++;
  }
    
  int get(int index, int snapId) {
    const auto& snaps = nums_[index];
    auto it = lower_bound(snaps.rbegin(), snaps.rend(), snapId,
        [](const auto& p, int snapId) {
          return p.first > snapId;
        });
    return it != snaps.rend() ? it->second : 0;
  }

 private:
  int snapId_ = 0;
  unordered_map<int, vector<pair<int, int>>> nums_;
};
