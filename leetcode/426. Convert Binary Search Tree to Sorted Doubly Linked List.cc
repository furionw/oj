// 2025-07-23
// Refer to the Editorial
class Solution {
 public:
  Node* treeToDoublyList(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }
    Node* first = nullptr;
    Node* last = nullptr;
    f(node, first, last);
    first->left = last;
    last->right = first;
    return first;
  }

 private:
  void f(Node* node, Node*& first, Node*& last) {
    if (node == nullptr) {
      return;
    }
    f(node->left, first, last);
    if (first == nullptr) {
      first = node;
    } else {
      node->left = last;
      last->right = node;
    }
    last = node;
    f(node->right, first, last);
  }
};

// 2025-07-23
// Method 1
class Solution {
 public:
  Node* treeToDoublyList(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }
    Node* first = node;
    auto l = treeToDoublyList(node->left);
    if (l != nullptr) {
      first = l;
      auto lLast = l->left;
      lLast->right = node;
      node->left = lLast;
    }
    Node* last = node;
    auto r = treeToDoublyList(node->right);
    if (r != nullptr) {
      last = r->left;
      auto rFirst = r;
      rFirst->left = node;
      node->right = rFirst;
    }
    first->left = last;
    last->right = first;
    return first;
  }
};
