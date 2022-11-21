// Date: 2022-11-21
// Method 2: Pre-process. `lower_bound`
class Solution {
 public:
  vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
    vector<int> nums;
    build(root, nums);
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (const auto& q : queries) {
      static vector<int> elem(2, -1);
      elem[0] = elem[1] = -1;
      auto it = lower_bound(nums.begin(), nums.end(), q);
      if (it == nums.end()) {
        elem[0] = nums.back();
      } else if (*it == q) {
        elem[0] = elem[1] = q;
      } else {
        elem[1] = *it;
        if (it != nums.begin()) {
          elem[0] = *(--it);
        }
      }
      res.push_back(elem);
    }
    return res;
  }
  
 private:
  void build(TreeNode* root, vector<int>& nums) {
    nums.push_back(root->val);
    if (root->left != nullptr) {
      build(root->left, nums);
    }
    if (root->right != nullptr) {
      build(root->right, nums);
    }
  }
};


// Method 1: Passed 36/37 cases. TLE
class Solution {
 public:
  vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
    int n = queries.size();
    vector<vector<int>> res(n, vector<int>());
    for (int i = 0; i < n; ++i) {
      res[i].push_back(minV(root, queries[i]));
      res[i].push_back(maxV(root, queries[i]));
    }
    return res;
  }
  
 private:
  int minV(TreeNode* root, int v) {
    if (root == nullptr) {
      return -1;
    }
    if (root->val == v) {
      return v;
    } else if (root->val < v) {
      return max(root->val, minV(root->right, v));
    } else {
      return minV(root->left, v);
    }
  }
  
  int maxV(TreeNode* root, int v) {
    if (root == nullptr) {
      return -1;
    }
    if (root->val == v) {
      return v;
    } else if (root->val > v) {
      int candidate = maxV(root->left, v);
      return candidate != -1 ? candidate : root->val;
    } else {
      return maxV(root->right, v);
    }
  }
};
