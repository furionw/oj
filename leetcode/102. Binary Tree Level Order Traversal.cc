// Copyright 2017 Qi Wang
// Date: 2017-11-09
// Copied from the LintCode 69 on 2017-10-21
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode * root) {
    vector<vector<int>> result;
    LevelOrder(root, &result, 0);
    return result;
  }
 
 private:
  void LevelOrder(TreeNode* root, vector<vector<int>>* result, int lvl) const {
    if (root == nullptr) return;
    if (lvl == result->size()) {
      result->push_back({root->val});
    } else {
      (*result)[lvl].push_back(root->val);
    }
    LevelOrder(root->left, result, lvl + 1);
    LevelOrder(root->right, result, lvl + 1);
  }
};

// Date: 2017-07-27
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return {};
    queue<pair<int, TreeNode*>> q;
    q.emplace(0, root);
    vector<vector<int>> result;
    while (!q.empty()) {
      const auto& p = q.front(); q.pop();
      if (p.first == result.size()) {
        result.emplace_back(1, p.second->val);
      } else {
        result.back().push_back(p.second->val);
      }
      if (p.second->left != nullptr) {
        q.emplace(p.first + 1, p.second->left);
      }
      if (p.second->right != nullptr) {
        q.emplace(p.first + 1, p.second->right);
      }
    }
    return result;
  }
};

class Solution 
{
public:
    vector<vector<int> > levelOrder(TreeNode *root) 
    {
      vector<vector<int>> ret;
        vector<TreeNode*> same_level_node[2];
    same_level_node[0].push_back(root);

        while (same_level_node[0].empty() == false)
        {
          vector<int> num;
          same_level_node[1].clear();
          
          for (size_t i = 0; i < same_level_node[0].size(); ++ i)
          {
            if (same_level_node[0][i] != NULL)
            {
              num.push_back( same_level_node[0][i]->val );
              same_level_node[1].push_back( same_level_node[0][i]->left );
              same_level_node[1].push_back( same_level_node[0][i]->right );
            }
          }
            if (num.size() != 0)
            {
              ret.push_back(num);
            }
          same_level_node[0] = same_level_node[1];
        }

        return ret;
    }
};