// Copyright 2016 Qi Wang
// Method 3
// Refer to: http://www.tuicool.com/articles/J7VR3y2
// Date: 2016-11-12
class Solution {
 public:
  inline int rob(TreeNode* root) {
    auto nums = dfs(root);
    return max(nums[0], nums[1]);
  }
 
 private:
  vector<int> dfs(TreeNode* root) {
    if (!root) return {0, 0};
    auto lNums = dfs(root->left);
    auto rNums = dfs(root->right);
    return {
      max(lNums[0], lNums[1]) + max(rNums[0], rNums[1]),
      root->val + lNums[0] + rNums[0]
    };
  }
};

// Method 2
// Memoization DP
// Date: 2016-11-12
class Solution {
 public:
  inline int rob(TreeNode* root) {
    return rob(root, false);
  }

 private:
  int rob(TreeNode* root, bool parentRobbed) {
    if (!root) {
      return 0;
    } else {
      auto key = make_pair(root, parentRobbed);
      if (res.find(key) != res.end()) {
        return res[key];
      } else {
        // Introduce "ans" here avoiding accessing res[key] twice.
        int ans = parentRobbed
            ? robChildren(root, false)
            : max(root->val + robChildren(root, true), robChildren(root, false));
        return res[key] = ans;
      }
    }
  }

  int robChildren(TreeNode* root, bool parentRobbed) {
    return rob(root->left, parentRobbed) + rob(root->right, parentRobbed);
  }

  map<pair<TreeNode*, bool>, int> res;
};

// Method 1
// TLE
// Date: 2016-11-12
class Solution {
 public:
  inline int rob(TreeNode* root) {
    return rob(root, false);
  }

 private:
  int rob(TreeNode* root, bool parentRobbed) const {
    if (!root) {
      return 0;
    } else {
      return parentRobbed
          ? robChildren(root, false)
          : max(root->val + robChildren(root, true), robChildren(root, false));
    }
  }

  int robChildren(TreeNode* root, bool parentRobbed) const {
    return rob(root->left, parentRobbed) + rob(root->right, parentRobbed);
  }
};
