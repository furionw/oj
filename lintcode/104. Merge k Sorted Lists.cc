// Copyright 2017 Qi Wang
// Date: 2017-10-11
// Method 2: divide and conquer
#include <list>
class Solution {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) return nullptr;
    list<ListNode*> ls(lists.begin(), lists.end());
    while (ls.size() > 1) {
      auto* first = ls.front();
      ls.pop_front();
      auto* second = ls.front();
      ls.pop_front();
      ls.push_back(Merge(first, second));
    }
    return ls.front();
  }
 
 private:
  ListNode* Merge(ListNode* lhs, ListNode* rhs) const {
    ListNode dummy;
    auto* cur = &dummy;
    for (; lhs != nullptr && rhs != nullptr; cur = cur->next) {
      if (lhs->val < rhs->val) {
        cur->next = lhs;
        lhs = lhs->next;
      } else {
        cur->next = rhs;
        rhs = rhs->next;
      }
    }
    cur->next = lhs != nullptr ? lhs : rhs;
    return dummy.next;
  }
};

// Date: 2017-10-11
// Method 1: priority_queue
struct comp {
  bool operator ()(const ListNode* lhs, const ListNode* rhs) const {
    return lhs->val > rhs->val;
  }
};
 
class Solution {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode*, vector<ListNode*>, comp> pq;
    for (auto* ptr : lists) {
      if (ptr != nullptr) pq.push(ptr);
    }
    ListNode dummy;
    for (ListNode* cur = &dummy; !pq.empty(); cur = cur->next) {
      auto* top = pq.top(); pq.pop();
      cur->next = top;
      top = top->next;
      if (top != nullptr) pq.push(top);
    }
    return dummy.next;
  }
};
