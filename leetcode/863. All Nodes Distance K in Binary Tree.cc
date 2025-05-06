// 2025-05-05
class Solution {
 public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    buildEdges(root);

    unordered_set<int> enqueued;
    queue<pair<int, int>> q;
    q.push({target->val, 0});
    enqueued.insert(target->val);
    vector<int> result;

    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      if (u.second == k) {
        result.push_back(u.first);
      } else if (u.second > k) {
        break;
      } else {
        for (int v : edges[u.first]) {
          if (enqueued.contains(v)) {
            continue;
          }
          q.push({v, u.second + 1});
          enqueued.insert(v);
        }
      }
    }

    return result;
  }
  
 private:
  void buildEdges(TreeNode* root) {
    buildEdge(root, root->left);
    buildEdge(root, root->right);
  }

  void buildEdge(TreeNode* p, TreeNode* c) {
    if (c == nullptr) {
      return;
    }
    int u = p->val;
    int v = c->val;
    edges[u].push_back(v);
    edges[v].push_back(u);
    buildEdges(c);
  }
  
  unordered_map<int, vector<int>> edges;
};