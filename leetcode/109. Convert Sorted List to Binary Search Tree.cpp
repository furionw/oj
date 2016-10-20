// Copyright [2016] <Stephen Wong>

// 2rd time, imitate the solution on August 2014
// Date: 2016-09-21
class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode *pre = nullptr, *slow = head, *fast = head;
    for (; fast->next != nullptr && fast->next->next != nullptr;
        slow = slow->next, fast = fast->next->next) pre = slow;
    auto root = new TreeNode(slow->val);
    root->right = sortedListToBST(slow->next);
    if (pre != nullptr) {
      pre->next = nullptr;
      root->left = sortedListToBST(head);
    }
    return root;
  }
};

// 1st time
// Date: 2016-09-21
class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    } else if (head->next == nullptr) {
      return new TreeNode(head->val);
    } else {
      auto slow = head, fast = head->next;
      for (; fast->next != nullptr && fast->next->next != nullptr;
          slow = slow->next, fast = fast->next->next) {}
      auto root = new TreeNode(slow->next->val);
      auto secondHead = slow->next->next;
      slow->next = nullptr;
      root->left = sortedListToBST(head);
      root->right = sortedListToBST(secondHead);
      return root;
    }
  }
};


// Date: 2014-08
class Solution 
{
public:
    TreeNode *sortedListToBST(ListNode *head) 
    {
        if (head == NULL)
        {
        	return NULL;
        }
        
        ListNode *pre=NULL, *slow=head, *fast=head;
        while (fast->next!=NULL && fast->next->next!=NULL)
        {
        	pre = slow;
        	slow = slow->next;
        	fast = fast->next->next;
        }
        TreeNode *tree = new TreeNode(slow->val);
        if (pre != NULL)
        {
            pre->next = NULL;
            tree->left = sortedListToBST(head);
        }
        tree->right = sortedListToBST(slow->next);

        return tree;
    }
};