// 2025-07-23
// Impl 2
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    auto slow = head;
    auto fast = head;
    while (fast != nullptr) {
      fast = fast->next;
      if (fast == nullptr) {
        return nullptr;
      }
      fast = fast->next;
      slow = slow->next;
      if (fast == slow) {
        break;
      }
    }
    if (fast == nullptr) {
      return nullptr;
    }

    for (; head != fast; head = head->next, fast = fast->next) {}
    return head;
  }
};

// 2025-07-23
// Impl 1
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    // Figure out circle size
    auto slow = head;
    auto fast = head;
    int circleSize = 0;
    while (fast != nullptr) {
      fast = fast->next;
      if (fast == nullptr) {
        return nullptr;
      }
      fast = fast->next;
      slow = slow->next;
      ++circleSize;
      if (fast == slow) {
        break;
      }
    }
    if (fast == nullptr) {
      return nullptr;
    }

    auto head2 = head;
    for (int i = 0; i < circleSize; ++i) {
      head2 = head2->next;
    }

    for (; head != head2; head = head->next, head2 = head2->next) {}
    return head;
  }
};

// Date: 2017-01-04
// Refer to: https://discuss.leetcode.com/topic/5284/concise-o-n-solution-by-using-c-with-detailed-alogrithm-description
// The above link has provided the solid proof.

// Date: ...
class Solution
{
public:
  ListNode* detectCycle(ListNode* head) 
  {
    ListNode* slow=head, *fast=head;
    while (fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
      {
        break;
      }
    }
    if ( fast==NULL || fast->next==NULL || fast->next->next==NULL)
    {
      return NULL;
    }
    slow=head;
    while (slow != fast)
    {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  } 
};
