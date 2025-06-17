// 2025-06-16
class Solution {
 public:
  vector<int> boundaryOfBinaryTree(TreeNode* root) {
    result.push_back(root->val);
    if (root->left != nullptr && !isLeaf(root->left)) {
      leftB(root->left);
    }
    // inspect();
    leaves(root->left);
    leaves(root->right);
    if (root->right != nullptr && !isLeaf(root->right)) {
      rightB(root->right);
    }
    return result;
  }

 private:
  // node is non-empty and non-leaf
  void leftB(TreeNode* node) {
    assert(node != nullptr);
    assert(!isLeaf(node));
    result.push_back(node->val);
    if (node->left != nullptr && !isLeaf(node->left)) {
      leftB(node->left);
      return;
    }
    if (node->left == nullptr && node->right != nullptr && !isLeaf(node->right)) {
      leftB(node->right);
    }
  }

  void leaves(TreeNode* node) {
    if (node == nullptr) {
      return;
    }
    if (isLeaf(node)) {
      result.push_back(node->val);
    }
    leaves(node->left);
    leaves(node->right);
  }

  void rightB(TreeNode* node) {
    assert(node != nullptr);
    if (node->right != nullptr && !isLeaf(node->right)) {
      rightB(node->right);
    }
    if (node->right == nullptr && node->left != nullptr && !isLeaf(node->left)) {
      rightB(node->left);
    }
    result.push_back(node->val);
  }

  bool isLeaf(TreeNode* node) {
    assert(node != nullptr);
    return node->left == nullptr && node->right == nullptr;
  }

  void inspect() {
    for (int r : result) {
      cout << r << ", ";
    }
    cout << endl;
  }

  vector<int> result;
};

// Date: 2017-04-20
class Solution {
 public:
  vector<int> boundaryOfBinaryTree(TreeNode* root) {
    // trivial case
    if (nullptr == root) return vector<int>();
    // non-trivial case
    vector<int> result(1, root->val);
    // left boundary
    LeftBoundary(root->left, result);
    // inorder travesal. If root is a leaf also, it has been added to the result
    // before Inorder() call
    Inorder(root->left, result);
    Inorder(root->right, result);
    // right boundary
    RightBoundary(root->right, result);
    return result;
  }

 private:
  void LeftBoundary(TreeNode* root, vector<int>& result) const {
    if (nullptr == root) return;
    // non-leaf
    while (nullptr != root->left || nullptr != root->right) {
      result.push_back(root->val);
      root = nullptr != root->left ? root->left : root->right;
    }
  }

  void Inorder(TreeNode* root, vector<int>& result) const {
    if (nullptr == root) return;
    // left subtree
    Inorder(root->left, result);
    // leaf
    if (nullptr == root->left && nullptr == root->right)
      result.push_back(root->val);
    // right subtree
    Inorder(root->right, result);
  }

  void RightBoundary(TreeNode* root, vector<int>& result) const {
    if (nullptr == root) return;
    // non-leaf
    if (nullptr != root->left || nullptr != root->right) {
      RightBoundary(nullptr != root->right ? root->right : root->left, result);
      result.push_back(root->val);
    }
  }
};

