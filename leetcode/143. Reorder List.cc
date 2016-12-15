// Copyright 2016 Qi Wang
// Date: 2016-12-15
class Solution {
 public:
  void reorderList(ListNode* head) {
    // return directly when list.length <= 2
    if (!head || !head->next) return;
    auto slow = head;
    // ‘Cause fast is initialized as head, left List could be longer than the right List
    for (auto fast = head; fast->next && fast->next->next;
        slow = slow->next, fast = fast->next->next) {}
    auto rHead = reverse(slow->next);
    slow->next = nullptr;
    // We name it as lHead corresponding to rHead
    for (auto lHead = head; lHead && rHead; ) {
      auto lNext = lHead->next;
      auto rNext = rHead->next;
      lHead->next = rHead;
      rHead->next = lNext;
      lHead = lNext;
      rHead = rNext;
    }
  }

 private:
  // it’s guaranteed that head is non-null
  ListNode* reverse(ListNode* head) {
    ListNode* pre = nullptr;
    while (head->next) {
      auto next = head->next;
      head->next = pre;
      pre = head;
      head = next;
    }
    head->next = pre;
    return head;
  }
};

// Date: 2016-06
class Solution 
{
public:
    void reorderList(ListNode *head) 
    {
      if (head == NULL || head->next==NULL)
      {
        return ;
      }

      // slow, towards, # = ceiling(n/2.0)
        ListNode *fast= head, *slow=head;
        for( ; fast->next!=NULL && fast->next->next!=NULL; slow = slow->next, fast = fast->next->next ) {}
        fast = slow->next;
        slow->next = NULL;
        slow = head;
        // fast, backwards, # = floor(n/2.0)
    ListNode* prev = fast;
    fast = fast->next;
    prev->next = NULL;
        while (fast != NULL)
        {
          ListNode* tmp = fast->next;
          fast->next = prev;
          prev = fast;
          fast = tmp;
        }
        fast = prev;

        for (ListNode* slow_next, *fast_next; fast != NULL; slow=slow_next, fast=fast_next)
        {
      slow_next = slow->next;
      fast_next = fast->next;
          slow->next = fast;
          fast->next = slow_next;
        }
    }
};
