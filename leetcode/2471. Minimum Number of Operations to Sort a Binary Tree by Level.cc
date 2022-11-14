// Date: 2022-11-12
class Solution {
 public:
  int minimumOperations(TreeNode* root) {
    int res = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      queue<TreeNode*> next;
      vector<int> nums;
      for (; !q.empty(); q.pop()) {
        auto node = q.front();
        nums.push_back(node->val);
        if (node->left != nullptr) {
          next.push(node->left);
        }
        if (node->right != nullptr) {
          next.push(node->right);
        }
      }
      q = next;
      auto nums2 = nums;
      sort(nums2.begin(), nums2.end());
       for (int i = 0; i < nums.size(); ++i) {
        for (; nums[i] != nums2[i]; ++res) {
          int dis = bSearch(nums2, nums[i]);
          swap(nums[i], nums[dis]);
        }
      }
    }
    return res;
  }
  
  int bSearch(const vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
      int mid = (l + r) >> 1;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return -1;
  }
};