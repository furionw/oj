// 2025-05-04
// TLE again
class Solution {
 public:
  vector<int> countSmaller(vector<int>& _nums) {
    nums = _nums;
    n = nums.size();
    t = vector<int>(4 * (n + 1));
    build(0, n - 1, 1);
    vector<int> result(n, 0);
    for (size_t i = 0; i < result.size() - 1; ++i) {
      result[i] = query(0, n - 1, 1, i + 1, n - 1, nums[i]);
    }
    return result;
  }

 private:
  int query(
      int l, int r, int idx,
      int qL, int qR, int num) {
    // cout << "foo " << l << ", " << r << ", " << idx << endl;
    // cout << "qL, qR = " << qL << ", " << qR << endl;
    // cout << "\n";
    assert(qL <= qR);
    if (l == qL && r == qR) {
      return query2(l, r, idx, num);
    }
    int mid = (l + r) / 2;
    if (qR <= mid) {
      return query(l, mid, left(idx), qL, qR, num);
    } else if (qL > mid) {
      return query(mid + 1, r, right(idx), qL, qR, num);
    } else {
      return query(l, mid, left(idx), qL, mid, num) +
          query(mid + 1, r, right(idx), mid + 1, qR, num);
    }
  }

  int query2(int l, int r, int idx, int num) {
    // cout << "bar " << l << ", " << r << ", " << idx << endl;
    if (l > r) {
      return 0;
    }
    if (l == r) {
      return t[idx] < num;
    }
    if (t[idx] < num) {
      return r - l + 1;
    }
    int mid = (l + r) / 2;
    return query2(l, mid, left(idx), num) + query2(mid + 1, r, right(idx), num);
  }

  inline int left(int i) const { return i << 1; }

  inline int right(int i) const { return left(i) + 1; }

  int build(int begin, int end, int idx) {
    if (begin == end) {
      // cout << idx << ", " << begin << endl;
      return t[idx] = nums[begin];
    }
    int mid = (begin + end) / 2;
    return t[idx] = max(
      build(begin, mid, left(idx)),
      build(mid + 1, end, right(idx))
    );
  }

  int n;
  vector<int> nums;
  vector<int> t;
};

// 2017-01-04
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
