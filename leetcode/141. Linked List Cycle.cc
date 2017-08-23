// Copyright 2017 Qi Wang
// Date: 2017-08-22
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr) return false;
    auto* fast = head->next;
    while (fast != nullptr && head != nullptr) {
      if (fast == head) return true;
      head = head->next;
      fast = fast->next;
      if (fast == nullptr) return false;
      fast = fast->next;
    }
    return false;
  }
};

// Date: 2017-01-04
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    auto slow = head, fast = head;
    while (fast != nullptr && fast->next != nullptr
        && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) return true;
    }
    return false;
  }
};

class Solution
{
public:
    bool hasCycle(ListNode *head) 
    {
        ListNode *slow=head, *fast=head;
        while (fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};
