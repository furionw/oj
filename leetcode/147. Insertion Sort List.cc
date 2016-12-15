// Copyright 2016 Qi Wang
// Method 3
// Refer to: http://www.jiuzhang.com/solutions/insertion-sort-list/
// Date: 2016-12-15
class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    if (!head) return head;
    unique_ptr<ListNode> dummy(new ListNode(INT_MIN));
    while (head) {
      auto next = head->next;
      auto temp = dummy.get();
      while (temp->next && temp->next->val < head->val)
        temp = temp->next;
      head->next = temp->next;
      temp->next = head;
      head = next;
    }
    return dummy->next;
  }
};

// Method 2
// Date: 2016-12-15
class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    if (!head) return head;
    int len = 0;
    for (auto cur = head; cur; cur = cur->next) ++len;
    vector<ListNode*> nodes(len);
    for (int i = 0; i < len; ++i) {
      nodes[i] = head;
      head = head->next;
    }
    for (int i = 1; i < len; ++i)
      for (int j = i - 1; j >= 0 && nodes[j + 1]->val < nodes[j]->val; --j)
        swap(nodes[j + 1]->val, nodes[j]->val);
    return nodes.front();
  }
};


// Method 1
// Date: 2016-12-15
class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    if (!head) return head;
    auto cur = head->next, tail = head;
    tail->next = nullptr;
    for (ListNode* next; cur; cur = next) {
      next = cur->next;
      cur->next = head;
      for (auto pre = head = cur; pre->next; pre = pre->next)
        if (pre->val > pre->next->val) swap(pre->val, pre->next->val);
    }
    return head;
  }
};

// Date: 2014-06
class Solution 
{
public:
    ListNode *insertionSortList(ListNode *head) 
    {
      // 可以处理head==NULL的情况，因此不用特判。
       for (auto i = head; i != NULL; i = i->next) 
       {
         for (auto j = head; j != i; j = j->next)
         {
           if (i->val < j->val)
           {
             int next_value = j->val;
             j->val = i->val;
             for (auto k = j->next; k != i; k = k->next)
             {
               int tmp = k->val;
               k->val = next_value;
               next_value = tmp;
             }
             i->val = next_value;
             break;
           }
         }
       }
       return head;
    }
};
