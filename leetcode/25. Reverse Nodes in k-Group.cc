// Copyright 2017 Qi Wang
// Date: 2017-11-11
// Please refer to the solution on 2017-08-04
class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k <= 1) return head;
    ListNode *result = nullptr, *prev = nullptr;
    while (head != nullptr) {
      ListNode *cur = head, *old_tail = nullptr;
      int cnt = 0;
      for (; head->next != nullptr && cnt < k - 1; ++cnt, head = head->next) {}
      if (cnt < k - 1) {
        if (prev != nullptr) prev->next = cur;
        return result != nullptr ? result : cur;
      }
      auto next = head->next;
      head->next = nullptr;
      auto p = Reverse(cur);
      if (result == nullptr) {
        result = p.first;
      } else {
        prev->next = p.first;
      }
      prev = p.second;
      head = next;
    }
    return result;
  }
 
 private:
  // Returns {new_head, new_tail}
  pair<ListNode*, ListNode*> Reverse(ListNode* node) const {
    ListNode* new_tail = node;
    ListNode* prev = nullptr;
    while (node != nullptr) {
      swap(prev, node->next);
      swap(prev, node);
    }
    return {prev, new_tail};
  }
};

// Date: 2017-08-04
class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    return k == 1 ? head : ReverseKGroup(head, k);
  }
 
 private:
  ListNode* ReverseKGroup(ListNode* head, int k) const {
    int len = 0;
    for (auto cur = head; cur != nullptr && len < k; cur = cur->next)
      ++len;
    if (len < k) return head;
    ListNode *cur = head, *prev = nullptr;
    for (int i = 0; i < k && cur != nullptr; ++i) {
      swap(cur->next, prev);
      swap(cur, prev);
    }
    if (cur != nullptr) {
      head->next = ReverseKGroup(cur, k);
    }
    return prev;
  }
};

// Date: 2016-12-21
class Solution {
 public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode dummy(0);
    dummy.next = head;
    for (auto tail = &dummy; tail;)
      tail = reverseKGroupIter(tail, k);
    return dummy.next;
  }

 private:
  ListNode *reverseKGroupIter(ListNode* preTail, int k) {
    auto curHead = preTail->next;
    if (!curHead) return nullptr;
    int len = 1;
    auto curTail = curHead;
    for (; curTail->next && len < k; curTail = curTail->next, ++len) {}
    if (len < k) return nullptr;
    preTail->next = curTail;
    auto nextHead = curTail->next;
    for (ListNode *pre = nullptr, *cur = curHead; cur != nextHead; ) {
      auto next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    curHead->next = nextHead;
    return curHead;
  }
};

// Date: 2014-06
class Solution 
{
public:
  ListNode *reverseKGroup(ListNode *head, int k) 
  {
    ListNode *cur=head, *prev, *next;

    while (cur != NULL)
    {
      int i;
      for (i=0, next=cur; i<k && next!=NULL; ++ i, next=next->next) {}
      if (i != k) 
      { 
        break;
      }
      for (int i = k-1; i >= 1; -- i)
      {
        ListNode *node = cur, *node_prev;
        for (int j = 0; j < i; ++ j)
        {
          node_prev = node;
          node = node->next;
        }
        node->next = node_prev;
        if (i==k-1 && head==cur)
        {
          head = node;
        } else if (i==k-1)
        {
          prev->next = node;
        }
      }
      prev = cur;
      cur->next = next;
      cur = cur->next;
    }

    return head;
  }
};
