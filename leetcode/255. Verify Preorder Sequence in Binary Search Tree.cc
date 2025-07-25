// 2025-07-23
// Method 1
class Solution {
 public:
  bool verifyPreorder(vector<int>& preorder) {
    return verifyPreorder(preorder, 0, preorder.size(), 0, 1e4 + 1);
  }

 private:
  bool verifyPreorder(vector<int>& preorder, int l, int r, int min, int max) {
    if (l == r) {
      return true;
    }
    int num = preorder[l];
    if (num <= min || num >= max) {
      return false;
    }
    int mid = l + 1;
    for (; mid < r; ++mid) {
      if (preorder[mid] > num) {
        break;
      }
    }
    return verifyPreorder(preorder, l + 1, mid, min, num)
        && verifyPreorder(preorder, mid, r, num, max);
  }
};

// Method 2: monotonic stack
class Solution {
 public:
  bool verifyPreorder(vector<int>& preorder) {
    int maxPopped = 0;
    stack<int> stk;
    for (int num : preorder) {
      if (num < maxPopped) {
        return false;
      }
      for (; !stk.empty() && stk.top() < num; stk.pop()) {
        maxPopped = max(maxPopped, stk.top());
      }
      stk.push(num);
    }
    return true;
  }
};
