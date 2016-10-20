// Morris travelsal
// Date: 2016-09-20
// Complexity: O(1) space, time?
class Solution {
 public:
  void recoverTree(TreeNode* root) {
    assert(root != nullptr);
    auto pre = root, cur = root;
    while (cur != nullptr) {
      if (cur->left == nullptr) {
        judge(pre, cur);
        pre = cur;
        cur = cur->right;
      } else {
        auto node = cur->left;
        for (; node->right != nullptr && node->right != cur; node = node->right) ;
        if (node->right == nullptr) {
          node->right = cur;
          cur = cur->left;
        } else {
          judge(pre, cur);
          node->right = nullptr;
          pre = cur;
          cur = cur->right;
        }
      }
    }
    swap(wrong1->val, wrong2->val);
  }

 private:
  inline void judge(TreeNode* pre, TreeNode* cur) {
    if (pre == nullptr) return;
    // A mistake
    if (pre->val > cur->val) {
      // wrong1 will be set only once
      wrong1 = wrong1 == nullptr? pre: wrong1;
      // wrong2 could be updated dynamically
      wrong2 = cur;
    }
  }

  TreeNode *wrong1 = nullptr, *wrong2 = nullptr;
};

// Date: 2016-09-20
// Complexity: O(lgn) space
class Solution {
 public:
  void recoverTree(TreeNode* root) {
    inorder(root);
    swap(s1->val, s2->val);
  }

 private:
  void inorder(TreeNode* cur) {
    if (nullptr == cur) return;
    inorder(cur->left);
    if (nullptr != pre && pre->val > cur->val) {
      // s1 will only be set once
      s1 = nullptr == s1? pre: s1;
      // s2 will be updated dynamically
      s2 = cur;
    }
    pre = cur;
    inorder(cur->right);
  }

  TreeNode *s1 = nullptr, *s2 = nullptr, *pre = nullptr;
};

// First time
// about 2014-07-20
class Solution 
{
public:
    void recoverTree(TreeNode *root) 
    {
        s1 = s2 = pre = NULL;
        gao(root);
        swap(s1->val, s2->val);
    }

private:
	void gao(TreeNode *cur)
	{	
		if (cur == NULL)
		{
			return ;
		}
		gao(cur->left);
		if (pre!=NULL && pre->val>cur->val)
		{
			if (s1 == NULL)
			{
				s1 = pre;
				s2 = cur;
			} else
			{
				s2 = cur;
			}
		}
		pre = cur;
		gao(cur->right);
	}
	TreeNode *s1, *s2, *pre;
};