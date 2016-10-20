#include <map>
#include <cmath>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    int countNodes(TreeNode* root) 
    {
        auto res = is_full_binary_tree(root);
        return res.first?
            pow(2, res.second) - 1:
            1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    pair<bool, int> is_full_binary_tree(TreeNode* node)
    {       
        int left_cnt = 0;
        for (auto n = node; n; n = n->left, ++ left_cnt) {}
        int right_cnt = 0;
        for (auto n = node; n; n = n->right, ++ right_cnt) {}
        return make_pair(left_cnt == right_cnt, left_cnt);
    }
};

// 算1023个点都会超时...
/*
class Solution 
{
public:
    int countNodes(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;

        for (auto node = q.front() ; node; node = q.front())
        {
            q.pop();
            q.push(node->left);
            q.push(node->right);
            ++ cnt;
        }

        return cnt;
    }
};*/

int main()
{
    Solution a;
    TreeNode node(1);
    cout << a.countNodes(&node) << endl;
}