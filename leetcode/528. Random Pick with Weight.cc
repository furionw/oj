// 2025-04-27
class Solution {
 public:
  Solution(vector<int>& w) {
    sums_ = w;
    for (size_t i = 1; i < sums_.size(); ++i) {
      sums_[i] += sums_[i - 1];
    }
  }
    
  int pickIndex() {
    int num = rand() % sums_.back();
    int l = 0, r = sums_.size() - 1;
    for (int mid = (l + r) / 2; l < r; mid = (l + r) / 2) {
      if (sums_[mid] <= num) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }

 private:
  vector<int> sums_;
};
