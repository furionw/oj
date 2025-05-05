// 2025-05-03
// Refer to the Editorial
class NumArray {
 public:
  NumArray(vector<int>& nums): n(nums.size()) {
    t.resize(2 * n);
    for (int i = n, j = 0; i < 2 * n; ++i, ++j) {
      t[i] = nums[j];
    }
    for (int i = n - 1; i > 0; --i) {
      t[i] = t[2 * i] + t[2 * i + 1];
    }
  }
    
  void update(int index, int val) {
    int delta = val - t[n + index];
    for (int i = n + index; i > 0; i /= 2) {
      t[i] += delta;
    }
  }
    
  int sumRange(int l, int r) {
    int result = 0;
    l += n;
    r += n;

    while (l <= r) {
      if (l % 2 == 1) {
        result += t[l];
        l = l / 2 + 1;
      } else {
        l /= 2;
      }
      if (r % 2 == 0) {
        result += t[r];
        r = r / 2 - 1;
      } else {
        r /= 2;
      }
    }

    return result;
  }

 private:
  int n;
  vector<int> t;
};

// 2025-05-02
struct Tree {
  Tree(Tree* l, Tree* r):
      left(l),
      right(r),
      x(l->x),
      y(r->y),
      s(l->s + r->s) {}

  Tree(int s, int i):
      s(s),
      x(i),
      y(i) {}

  void update(int idx, int delta) {
    s += delta;

    if (left == nullptr) {
      return;
    }

    if (left->contains(idx)) {
      left->update(idx, delta);
    } else {
      right->update(idx, delta);
    }
  }

  bool contains(int idx) {
    return x <= idx && idx <= y;
  }

  int sumRange(int xx, int yy) {
    if (x == xx && y == yy) {
      return s;
    }

    if (right->x <= xx) {
      return right->sumRange(xx, yy);
    } else if (yy <= left->y) {
      return left->sumRange(xx, yy);
    } else {
      return left->sumRange(xx, left->y) + right->sumRange(right->x, yy);
    }
  }

  int s;
  int x, y;
  Tree* left = nullptr;
  Tree* right = nullptr;
};

class NumArray {
 public:
  NumArray(vector<int>& n): nums(n) {
    t = buildTree(0, nums.size() - 1);
  }
    
  void update(int index, int val) {
    int delta = val - nums[index];
    nums[index] = val;
    t->update(index, delta);
  }
    
  int sumRange(int left, int right) {
    return t->sumRange(left, right);
  }

 private:
  Tree* buildTree(int x, int y) {
    if (x == y) {
      return new Tree(nums[x], x);
    }
    int mid = (x + y) / 2;
    auto left = buildTree(x, mid);
    auto right = buildTree(mid + 1, y);
    return new Tree(left, right);
  }
  
  Tree* t;
  vector<int> nums;
};


// 2016-12-22
class NumArray {
 public:
  NumArray(vector<int> &nums) : CAPACITY(nums.size()) {
    if (CAPACITY == 0) return;
    sums_.resize((CAPACITY + 1) << 2);
    build(1, CAPACITY, ROOT, nums);
  }

  void update(int i, int val) {
    update(i + 1, val, ROOT, 1, CAPACITY);
  }

  int sumRange(int i, int j) {
    return sum(i + 1, j + 1, ROOT, 1, CAPACITY);
  }

 private:
  inline int left(int i) const { return i << 1; }

  inline int right(int i) const { return left(i) + 1; }

  int build(int begin, int end, int idx, const vector<int>& nums) {
    if (begin == end) {
      return sums_[idx] = nums[begin - 1];
    } else {
      int mid = begin + end >> 1;
      return sums_[idx] = build(begin, mid, left(idx), nums)
          + build(mid + 1, end, right(idx), nums);
    }
  }

  int sum(int qL, int qR, int idx, int l, int r) {
    if (qL == l && qR == r)
      return sums_[idx];
    int mid = l + r >> 1;
    if (qR <= mid) {
      return sum(qL, qR, left(idx), l, mid);
    } else if (qL > mid) {
      return sum(qL, qR, right(idx), mid + 1, r);
    } else {
      return sum(qL, mid, left(idx), l, mid)
          + sum(mid + 1, qR, right(idx), mid + 1, r);
    }
  }

  int update(int qIdx, int val, int idx, int l, int r) {
    if (l == r && l == qIdx) return sums_[idx] = val;
    int mid = l + r >> 1;
    return sums_[idx] = qIdx <= mid
        ? update(qIdx, val, left(idx), l, mid) + sums_[right(idx)]
        : sums_[left(idx)] + update(qIdx, val, right(idx), mid + 1, r);
  }

  vector<int> sums_;
  const int CAPACITY;
  static constexpr int ROOT = 1;
};
