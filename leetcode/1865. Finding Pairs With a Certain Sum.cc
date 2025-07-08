// 2025-07-06
// Passed
class FindSumPairs {
 public:
  FindSumPairs(vector<int>& nums1, vector<int>& nums2):
      nums1_(move(nums1)),
      nums2_(move(nums2)) {
    for (int num2 : nums2_) {
      ++num2ToCnts_[num2];
    }
  }
    
  void add(int index, int val) {
    --num2ToCnts_[nums2_[index]];
    nums2_[index] += val;
    ++num2ToCnts_[nums2_[index]];
  }
    
  int count(int tot) {
    int result = 0;
    for (int num1 : nums1_) {
      result += num2ToCnts_[tot - num1];
    }
    return result;
  }

 private:
  vector<int> nums1_;
  vector<int> nums2_;
  unordered_map<int, int> num2ToCnts_;
};


// 2025-07-06
// TLE
class FindSumPairs {
 public:
  FindSumPairs(vector<int>& nums1, vector<int>& nums2):
      nums1_(move(nums1)),
      nums2_(move(nums2)) {
    for (int num1 : nums1_) {
      for (int num2 : nums2_) {
        ++totToCnts_[num1 + num2];
      }
    }
  }
    
  void add(int index, int val) {
    for (int num1 : nums1_) {
      --totToCnts_[num1 + nums2_[index]];
      ++totToCnts_[num1 + nums2_[index] + val];
    }
    nums2_[index] += val;
  }
    
  int count(int tot) {
    return totToCnts_[tot];
  }

 private:
  vector<int> nums1_;
  vector<int> nums2_;
  unordered_map<int, int> totToCnts_;
};
