// Copyright 2017 Qi Wang
// Date: 2017-07-11
// Method 3: Iterate
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (nullptr != head) {
      swap(prev, head->next);
      swap(prev, head);
    }
    return prev;
  }
};

// Date: 2017-07-11
// Method 2: Recursive. Refer to the solution in 2015-06
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* result;
    Recursive(nullptr, head, &result);
    return result;
  }

 private:
  void Recursive(ListNode* prev, ListNode* cur, ListNode** result) const {
    if (nullptr != cur) {
      swap(prev, cur->next);
      Recursive(cur, prev, result);
    } else {
      *result = prev;
    }
  }
};


// Date: 2017-07-11
// Method 1: Recursive
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* result = nullptr;
    if (nullptr != head) {
      ReverseList(nullptr, head, &result);
    }
    return result;
  }

 private:
  void ReverseList(ListNode* prev, ListNode* head, ListNode** result) {
    if (nullptr != head->next) {
      ReverseList(head, head->next, result);
    } else {
      *result = head;
    }
    head->next = prev;
   }
};

// Date: 2015-06
class Solution
{
public:
  ListNode* reverseList(ListNode* head)
  {
    // return iteratively(head);
    return recursively(nullptr, head);
  }

private:
  ListNode* iteratively(ListNode *head)
  {
    auto cur = head;
    for (ListNode* pre = nullptr; cur != nullptr;)
    {
      if (cur->next == nullptr)
      {
        cur->next = pre;
        return cur;
      } else
      {
        swap(pre, cur->next);
        swap(pre, cur);
      }
    }
    return nullptr;
  }

  // note that this tail recursive algo should be transformed into iterate algo to obtain the better performance
  ListNode* recursively(ListNode *pre, ListNode *cur)
  {
    if (cur == nullptr)
    {
      return pre;
    } else
    {
      swap(pre, cur->next);
      return recursively(cur, pre);
    }
  }
};
