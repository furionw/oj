// Copyright 2017 Qi Wang
// Date: 2017-10-19
// Method 3
// Refer to: https://discuss.leetcode.com/topic/98440/java-c-three-simple-methods-choose-one-you-like
// Time complexity: O(n)
class Solution {
 public:
  bool findTarget(TreeNode* root, int k) {
    vector<int> nums;
    InorderTraversal(root, &nums);
    if (nums.size() <= 1) return false;
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      if (nums[l] + nums[r] == k) {
        return true;
      } else if (nums[l] + nums[r] < k) {
        ++l;
      } else {
        --r;
      }
    }
    return false;
  }

 private:
  void InorderTraversal(TreeNode* root, vector<int>* nums) {
    if (root == nullptr) return;
    InorderTraversal(root->left, nums);
    nums->push_back(root->val);
    InorderTraversal(root->right, nums);
  }
};

// Date: 2017-10-19
// Method 2
// Time complexity: O(n)
class Solution {
 public:
  bool findTarget(TreeNode* root, int k) {
    unordered_set<int> s;
    return FindTarget(root, k, &s);
  }

 private:
  bool FindTarget(TreeNode* root, int target, unordered_set<int>* s) const {
    if (root == nullptr) return false;
    int other = target - root->val;
    if (s->count(other)) return true;
    s->insert(root->val);
    return FindTarget(root->left, target, s) ||
           FindTarget(root->right, target, s);
  }

  unordered_set<int> s;
};

// Date: 2017-08-06
// Method 1
// Time complexity: O(nlogn)
class Solution {
 public:
  bool findTarget(TreeNode* root, int k) {
    return FindTarget(root, root, k);
  }
 
 private:
  bool FindTarget(TreeNode* cur, TreeNode* root, int k) const {
    if (cur == nullptr) return false;
    return (cur->val << 1 != k && Find(root, k - cur->val)) ||
           FindTarget(cur->left, root, k) || FindTarget(cur->right, root, k);
  }
 
  bool Find(TreeNode* root, int k) const {
    if (root == nullptr) {
      return false;
    } else if (root->val == k) {
      return true;
    } else if (root->val > k) {
      return Find(root->left, k);
    // root->val < k
    } else {
      return Find(root->right, k);
    }
  }
};
