// Copyright 2016 Qi Wang
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
