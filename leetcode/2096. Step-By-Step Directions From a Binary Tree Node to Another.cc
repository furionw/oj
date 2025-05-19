// 2025-05-17
class Solution {
 public:
  string getDirections(TreeNode* root, int startValue, int destValue) {
    visit(root, nullopt);
    dest = destValue;
    dfs(startValue);
    return result;
  }

 private:
  void visit(TreeNode* node, optional<int> up) {
    int v = node->val;
    if (up != nullopt) {
      ups[v] = *up;
    }
    if (node->left != nullptr) {
      lefts[v] = node->left->val;
      visit(node->left, v);
    }
    if (node->right != nullptr) {
      rights[v] = node->right->val;
      visit(node->right, v);
    }
  }

  bool dfs(int node) {
    if (node == dest) {
      return true;
    }

    visited[node] = true;
    if (lefts.contains(node) && !visited[lefts[node]]) {
      result += "L";
      if (dfs(lefts[node])) {
        return true;
      }
      result.pop_back();
    }

    if (rights.contains(node) && !visited[rights[node]]) {
      result += "R";
      if (dfs(rights[node])) {
        return true;
      }
      result.pop_back();
    }

    if (ups.contains(node) && !visited[ups[node]]) {
      result += "U";
      if (dfs(ups[node])) {
        return true;
      }
      result.pop_back();
    }
    return false;
  }

  unordered_map<int, int> lefts, rights, ups;
  unordered_map<int, bool> visited;
  string result;
  int dest;
};