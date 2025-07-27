// 2025-07-26
class SparseVector {
 public:
  SparseVector(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        nums_.emplace_back(i, nums[i]);
      }
    }
  }
    
  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    int i = 0;
    int j = 0;
    int result = 0;
    while (i < nums_.size() && j < vec.nums_.size()) {
      if (nums_[i].first == vec.nums_[j].first) {
        result += nums_[i].second * vec.nums_[j].second;
        ++i;
        ++j;
      } else if (nums_[i].first < vec.nums_[j].first) {
        ++i;
      } else {
        ++j;
      }
    }
    return result;
  }

 private:
  vector<pair<int, int>> nums_;
};
