// Copyright 2016 Qi Wang
// Method 3: merge sort without "len"
// Refer to the solution in 2014-06
// Date: 2016-12-15
class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    auto slow = head;
    for (auto fast = head; fast->next && fast->next->next;
        slow = slow->next, fast = fast->next->next) {}
    auto rHead = slow->next;
    slow->next = nullptr;
    auto lRes = sortList(head), rRes = sortList(rHead);
    ListNode *res;
    // initial the head of the list to return
    advance(res, lRes, rRes);
    auto tail = res;
    for (; lRes && rRes; tail = tail->next)
      advance(tail->next, lRes, rRes);
    tail->next = lRes ? lRes : rRes;
    return res;
  }

 private:
  void advance(ListNode* &ptr, ListNode* &lRes, ListNode* &rRes) const {
    if (lRes->val < rRes->val) {
      ptr = lRes;
      lRes = lRes->next;
    } else {
      ptr = rRes;
      rRes = rRes->next;
    }
  }
};

// Merge sort
// Method 2
// Date: 2016-12-15
class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    int len = 0;
    for (auto cur = head; cur; cur = cur->next) ++len;
    if (len <= 1) return head;
    auto rPre = head;
    for (int i = 0; i < (len >> 1) - 1; ++i) rPre = rPre->next;
    auto rHead = rPre->next;
    rPre->next = nullptr;
    auto lRes = sortList(head), rRes = sortList(rHead);
    ListNode *res;
    // initial the head of the list to return
    advance(res, lRes, rRes);
    auto tail = res;
    for (; lRes && rRes; tail = tail->next)
      advance(tail->next, lRes, rRes);
    tail->next = lRes ? lRes : rRes;
    return res;
  }

 private:
  void advance(ListNode* &ptr, ListNode* &lRes, ListNode* &rRes) const {
    if (lRes->val < rRes->val) {
      ptr = lRes;
      lRes = lRes->next;
    } else {
      ptr = rRes;
      rRes = rRes->next;
    }
  }
};

// Method 1
// Quicksort, this solution might degenerate to O(n^2)
// Date: 2016-12-15
class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    unique_ptr<ListNode> less(new ListNode(DUMMY));
    unique_ptr<ListNode> noLess(new ListNode(DUMMY));
    auto pivot = head;
    for (head = head->next; head;) {
      auto next = head->next;
      if (head->val < pivot->val) {
        head->next = less->next;
        less->next = head;
      } else {
        head->next = noLess->next;
        noLess->next = head;
      }
      head = next;
    }
    if (!less->next) {
      pivot->next = sortList(noLess->next);
      return pivot;
    } else {
      auto res = sortList(less->next);
      auto tail = res;
      for (; tail->next; tail = tail->next) {}
      tail->next = pivot;
      pivot->next = sortList(noLess->next);
      return res;
    }
  }

 private:
  static constexpr int DUMMY = 0;
};

// 2014-06
class Solution
{
public:
  ListNode* sortList(ListNode* head)
  {
    if (head == NULL || head->next==NULL)
    {
      return head;
    }

    ListNode* fast=head, *slow=head;
    for ( ; fast->next!=NULL&&fast->next->next!=NULL; fast=fast->next->next, slow=slow->next) {}
    fast = slow;
    slow = slow->next;
    fast->next = NULL;
    fast = sortList(head); // half before 
    slow = sortList(slow); // half after

    return merge(fast, slow);
  }

  ListNode* merge(ListNode* before, ListNode* after)
  {
    ListNode* head;
    if ( before->val < after->val )
    {
      head = before;
      before = before->next;
    } else
    {
      head = after;
      after = after->next;
    }

    ListNode* now = head;
    while ( before!=NULL && after!=NULL )
    {
      if (before->val < after->val)
      {
        now->next = before;
        before = before->next;
      } else
      {
        now->next = after;
        after = after->next;
      }
      now = now->next;      
    }
    if (before != NULL) { now->next = before; }
    if (after  != NULL) { now->next = after; }
    return head;
  }
};