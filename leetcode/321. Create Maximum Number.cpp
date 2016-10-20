// Copyright 2016 Qi Wang
// Date: 2016-10-09
inline bool greaterComp(const vector<int>& lhs, size_t i, const vector<int>& rhs,
    size_t j) {
  for (; i < lhs.size() && j < rhs.size(); ++i, ++j)
    if (lhs[i] != rhs[j]) return lhs[i] > rhs[j];
  // return the string with longer length when the preceeding digits are the same
  return i != lhs.size();
}

class Solution {
public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> res(k, 0);
    for (size_t i = 0; i <= k; ++i) {
      if (i > nums1.size() || k - i > nums2.size()) continue;
      auto largest1 = getLargestDigits(nums1, i);
      auto largest2 = getLargestDigits(nums2, k - i);
      vector<int> temp;
      size_t idx1 = 0, idx2 = 0;
      while (idx1 < largest1.size() && idx2 < largest2.size())
        temp.push_back(greaterComp(largest1, idx1, largest2, idx2)
          ? largest1[idx1++]
          : largest2[idx2++]);
      while (idx1 < largest1.size()) temp.push_back(largest1[idx1++]);
      while (idx2 < largest2.size()) temp.push_back(largest2[idx2++]);
      res = greaterComp(res, 0, temp, 0) ? res : temp;
    }
    return res;
  }

private:
  inline vector<int> getLargestDigits(const vector<int>& nums,
      size_t digitsToPick) const {
    vector<int> res;
    for (size_t i = 0; i < nums.size(); ++i) {
      while (!res.empty() && nums.size() - i + res.size() > digitsToPick
        && res.back() < nums[i]) res.pop_back();
      if (res.size() < digitsToPick) res.push_back(nums[i]);
    }
    return res;
  }
};
