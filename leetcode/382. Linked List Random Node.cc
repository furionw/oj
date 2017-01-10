// Copyright 2017 Qi Wang
// Date: 2017-01-04
class Solution {
 public:
  Solution(ListNode* head) : head_(head) {}

  int getRandom() {
    if (head_ == nullptr) return 1;
    int cnt = 0, res;
    for (auto cur = head_; cur != nullptr; cur = cur->next)
      // Take care the range of rand()
      if (rand() % ++cnt == 0) res = cur->val;
    return res;
  }

 private:
  ListNode* head_;
};

// Date: 2016-11-30
// Method 2
// Reservoir sampling
class Solution {
 public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode* head) : head_(head) {
    for (; head; head = head->next) ++len_;
    distribution_ = uniform_int_distribution<int>(1, INT_MAX);
  }

  /** Returns a random node's value. */
  int getRandom() {
    int res = 0, cnt = 1;
    for (auto head = head_; head; head = head->next) {
      if (distribution_(generator_) % cnt == 0) res = head->val;
      ++cnt;
    }
    return res;
  }

 private:
  default_random_engine generator_;
  uniform_int_distribution<int> distribution_;
  ListNode *head_;
  int len_ = 0;
};

// Date: 2016-11-30
// Method 1: with O(n) space complexity
class Solution {
 public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode* head) {
    for (; head; head = head->next)
      vals_.push_back(head->val);
  }

  /** Returns a random node's value. */
  int getRandom() {
    return vals_[rand() % vals_.size()];
  }

 private:
  vector<int> vals_;
};
