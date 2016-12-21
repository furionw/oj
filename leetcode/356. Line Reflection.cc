// Copyright 2016 Qi Wang
// Difficulty: Medium
// Date: 2016-12-21
class Solution {
 public:
  bool isReflected(vector<pair<int, int>>& points) {
    if (points.empty()) return true;
    unordered_map<int, vector<int>> coor;
    for (auto& p : points) coor[p.second].push_back(p.first);
    // find center
    double xCenter = findCenter(coor.begin()->second);
    for (auto& elem : coor)
      if (!valid(elem.second, xCenter))
        return false;
    return true;
  }

 private:
  double findCenter(vector<int>& xs) {
    sort(xs.begin(), xs.end());
    removeDuplicate(xs);
    // odd
    return xs.size() & 1
        ? xs[xs.size() >> 1]  // odd size
        : (xs.front() + xs.back()) / 2.;  // even size
  }

  bool valid(vector<int>& xs, double xCenter) {
    sort(xs.begin(), xs.end());
    removeDuplicate(xs);
    size_t mid = xs.size() >> 1;
    if (xs.size() & 1 && xs[mid] != xCenter) return false;
    xCenter *= 2;
    for (size_t i = 0; i < mid; ++i)
      if (xs[i] + xs[xs.size() - i - 1] != xCenter)  // xCenter has been double
        return false;
    return true;
  }

  // nums should be sorted already and non-empty
  void removeDuplicate(vector<int>& nums) {
    size_t pre = 0;
    for (int num : nums)
      if (nums[pre] != num)
        nums[++pre] = num;
    nums.resize(pre + 1);
  }
};


// Date: 2016-12-21
// Compile Error !!!
class Solution {
 public:
  bool isReflected(vector<pair<int, int>>& points) {
    unordered_map<int, vector<int>> coor;
    for (auto& p : points) coor[p.second].push_back(p.first);
    // find center
    double xCenter = findCenter(coor.begin()->second);
    for (auto& elem : coor)
      if (valid(elem.second, xCenter))
    return all_of(coor.begin(), coor.end(),
        [this, xCenter](pair<int, vector<int>>& elem) {
            return valid(elem.second, xCenter);
        });
  }

 private:
  double findCenter(vector<int>& xs) {
    sort(xs.begin(), xs.end());
    // odd
    return xs.size() & 1
        ? xs[xs.size() >> 1]  // odd size
        : (xs.front() + xs.back()) / 2.;  // even size
  }

  bool valid(vector<int>& xs, double xCenter) {
    sort(xs.begin(), xs.end());
    size_t mid = xs.size() >> 1;
    if (xs.size() & 1 && xs[mid] != xCenter) return false;
    xCenter *= 2;
    for (size_t i = 0; i < mid; ++i)
      if (xs[i] + xs[xs.size() - i - 1] != xCenter)  // xCenter has been double
        return false;
    return true;
  }
};
