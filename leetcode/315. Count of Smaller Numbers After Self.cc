// Copyright 2017 Qi Wang
// Date: 2017-01-04
// Method 1: TLE
class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    if (nums.empty()) return nums;
    // maximal values
    vector<int> tree((nums.size() + 1) << 2);
    build(tree, 1, 0, nums.size() - 1, nums);
    vector<int> res(nums.size(), 0);
    for (int i = 0; i + 1 < nums.size(); ++i)
      res[i] = countSmallerElem(tree, 1, 0, nums.size() - 1,
          nums[i], i + 1, nums.size() - 1);
    return res;
  }

 private:
  void build(vector<int>& tree, int t_idx, int t_left, int t_right,
      const vector<int>& nums) const {
    if (t_left == t_right) {
      tree[t_idx] = nums[t_left];
    } else {
      int mid = (t_left + t_right) >> 1;
      build(tree, left(t_idx), t_left, mid, nums);
      build(tree, right(t_idx), mid + 1, t_right, nums);
      tree[t_idx] = max(tree[left(t_idx)], tree[right(t_idx)]);
    }
  }

  int countSmallerElem(const vector<int>& tree, int t_idx,
      int t_left, int t_right, int cur, int q_left, int q_right) const {
    if (t_left == q_left && t_right == q_right) {
      if (t_left == t_right) return cur > tree[t_idx];
      int mid = (t_left + t_right) >> 1;
      return cur > tree[t_idx]
          ? t_right - t_left + 1
          : countSmallerElem(tree, left(t_idx), t_left, mid, cur, q_left, mid)
             + countSmallerElem(tree, right(t_idx), mid + 1, t_right, cur,
                 mid + 1, q_right);
    }
    int mid = (t_left + t_right) >> 1;
    if (mid < q_left) {
      return countSmallerElem(tree, right(t_idx), mid + 1, t_right,
          cur, q_left, q_right);
    } else if (mid >= q_right) {
      return countSmallerElem(tree, left(t_idx), t_left, mid,
          cur, q_left, q_right);
    } else {
      return countSmallerElem(tree, left(t_idx), t_left, mid, cur, q_left, mid)
          + countSmallerElem(tree, right(t_idx), mid + 1, t_right, cur,
              mid + 1, q_right);      
    }
  }

  int left(int idx) const { return idx << 1; }
  int right(int idx) const { return left(idx) + 1; }
};
