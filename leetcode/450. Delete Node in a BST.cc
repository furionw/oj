// Copyright 2016 Qi Wang
// Date: 2016-12-26
class Solution {
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;
    if (root->val > key) {
      root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
      root->right = deleteNode(root->right, key);
    } else {
      if (!root->left && !root->right) {
        delete root;
        root = nullptr;
      } else if (!root->right) {
        auto left = root->left;
        delete root;
        root = left;
      } else if (!root->left) {
        auto right = root->right;
        delete root;
        root = right;
      } else {
        int max = findMax(root->left);
        root->val = max;
        root->left = deleteNode(root->left, max);
      }
    }
    return root;
  }

 private:
  int findMax(TreeNode* root) const {
    int max = root->val;
    for (; root->right; root = root->right)
      max = root->right->val;
    return max;
  }
};

// Method 2
// Refer to: http://code.runnable.com/VUTjJDME6nRv_HOe/delete-node-from-bst-for-c%2B%2B
// Date: 2016-11-20
class Solution {
 public:
  inline TreeNode* deleteNode(TreeNode *root, int key) {
    if (root) {
      if (root->val > key) {
        root->left = deleteNode(root->left, key);
      } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
      } else {
        if (!root->left && !root->right) {
          // no child
          delete root;
          root = nullptr;
        } else if (!root->right) {
          // 1 left child
          auto left = root->left;
          delete root;
          root = left;
        } else if (!root->left) {
          // 1 right child
          auto right = root->right;
          delete root;
          root = right;
        } else {
          // 2 child
          key = findMax(root->left);
          root->val = key;
          root->left = deleteNode(root->left, key);
        }
      }
    }
    return root;
  }

 private:
  int findMax(TreeNode* root) {
    while (root->right) root = root->right;
    return root->val;
  }
};

// Method 1
// Date: 2016-11-20
class Solution {
 public:
  inline TreeNode* deleteNode(TreeNode *root, int key) {
    if (root) {
      if (root->val == key) {
        root = deleteNode(root);
      } else if (root->val > key) {
        root->left = deleteNode(root->left, key);
      } else {
        root->right = deleteNode(root->right, key);
      }
    }
    return root;
  }

 private:
  TreeNode* deleteNode(TreeNode *root) const {
    auto oldRoot = root;
    if (!root->left && !root->right) {
      root = nullptr;
    } else if (!root->left) {
      root = root->right;
    } else {
      auto left = root->left;
      if (left->right) {
        auto rightMostPre = left;
        auto rightMost = rightMostPre->right;
        while (rightMost->right) {
          rightMostPre = rightMost;
          rightMost = rightMost->right;
        }
        rightMostPre->right = nullptr;
        // make rightMost as the new root
        rightMost->right = root->right;
        root = rightMost;
        insert(root, left);
      } else {
        left->right = root->right;
        root = left;
      }
    }
    delete oldRoot;
    return root;
  }

  TreeNode* insert(TreeNode *root, TreeNode *node) const {
    // assert(node);
    if (!root) {
      return node;
    } else {
      // not allow duplicate elements
      // assert(root->val != node->val);
      if (root->val > node->val) {
        root->left = insert(root->left, node);
      } else {
        root->right = insert(root->right, node);
      }
    }
    return root;
  }
};
