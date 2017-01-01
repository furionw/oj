// Copyright 2016 Qi Wang
// Date: 2017-01-01
// Method 2: refer to https://discuss.leetcode.com/topic/30597/java-5ms-iterative-following-hint-o-klogn-time-and-space
class Solution {
 public:
  vector<int> closestKValues(TreeNode* root, double target, int k) {
    stack<TreeNode*> pre, succ;
    for (auto cur = root; cur != nullptr; ) {
      if (cur->val <= target) {
        pre.push(cur);
        cur = cur->right;
      } else {
        succ.push(cur);
        cur = cur->left;
      }
    }
    vector<int> res;
    while (k--) {
      if (succ.empty()) {
        res.push_back(getPredecessor(pre));
      } else if (pre.empty()) {
        res.push_back(getSuccessor(succ));
      } else if (fabs(pre.top()->val - target)
          < fabs(succ.top()->val - target)) {
        res.push_back(getPredecessor(pre));
      } else {
        res.push_back(getSuccessor(succ));
      }
    }
    return res;
  }

 private:
  int getPredecessor(stack<TreeNode*>& stk) const {
    assert(!stk.empty());
    auto res = stk.top();
    stk.pop();
    for (auto cur = res->left; cur != nullptr; cur = cur->right)
      stk.push(cur);
    return res->val;
  }

  int getSuccessor(stack<TreeNode*>& stk) const {
    assert(!stk.empty());
    auto res = stk.top();
    stk.pop();
    for (auto cur = res->right; cur != nullptr; cur = cur->left)
      stk.push(cur);
    return res->val;
  }
};

// Date: 2016-12-31
// Method 1
class Solution {
 public:
  vector<int> closestKValues(TreeNode* root, double target, int k) {
    priority_queue<pair<double, int>> q;
    closestKValues(root, target, k, q);
    vector<int> res;
    while (!q.empty()) {
      res.push_back(q.top().second);
      q.pop();
    }
    return res;
  }

 private:
  void closestKValues(TreeNode* root, double target, int k,
      priority_queue<pair<double, int>>& q) const {
    if (root == nullptr) return;
    q.emplace(fabs(root->val - target), root->val);
    if (q.size() > k) q.pop();
    closestKValues(root->left, target, k, q);
    closestKValues(root->right, target, k, q);
  }
};
