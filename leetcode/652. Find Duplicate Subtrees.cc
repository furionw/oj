// Date: 2017-08-06
// Weekly Contest 43
// Refer to cchao's solution.
class Solution {
 private:
  using NodeLabel = tuple<int, int, int>;
 
  struct NodeState {
    NodeState() {}
    NodeState(int id, int cnt) : id(id), cnt(cnt) {}
    int id, cnt;
  };
 
 public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    map<NodeLabel, NodeState> label_to_state_map;
    // "0" is remain for nullptr
    int unique_cnt = 1;
    vector<TreeNode*> result;
    F(root, &label_to_state_map, &unique_cnt, &result);
    return result;
  }
 
 private:
  int F(
      TreeNode* root,
      map<NodeLabel, NodeState>* label_to_state_map,
      int* unique_cnt,
      vector<TreeNode*>* result) {
    if (root == nullptr) return 0;
    NodeLabel key = {
      root->val,
      F(root->left, label_to_state_map, unique_cnt, result),
      F(root->right, label_to_state_map, unique_cnt, result)
    };
    if (label_to_state_map->find(key) == label_to_state_map->end()) {
      (*label_to_state_map)[key] = NodeState((*unique_cnt)++, 1);
    } else if (++(*label_to_state_map)[key].cnt == 2) {
      result->push_back(root);
    }
    return (*label_to_state_map)[key].id;
  }
};

// cchao's solution.
class Solution {
  int id;
  map<tuple<int, int, int>, int> m;
  map<int, int> cnt;
  vector<TreeNode*> dup;
  int dfs(TreeNode *x) {
    if (!x) return 0;
    tuple<int, int, int> tmp = {dfs(x->left), dfs(x->right), x->val};
    if (!m.count(tmp)) m[tmp] = id++;
    int ret = m[tmp];
    if (++cnt[ret] == 2) dup.push_back(x);
    return ret;
  }
public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    id = 1;
    cnt.clear();
    m.clear();
    dup.clear();
    dfs(root);
    return dup;
  }
};
