// Copyright 2016 Qi Wang
// Date: 2016-12-16
class Solution {
 public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) return nullptr;
    auto node = nodes_[head->label];
    if (!node) {
      node = nodes_[head->label] = new RandomListNode(head->label);
      // The checkings are really necessary here avoding recursively too deep
      if (head->next)
        node->next = nodes_[head->next->label]
            ? nodes_[head->next->label] : copyRandomList(head->next);
      if (head->random)
        node->random = nodes_[head->random->label]
            ? nodes_[head->random->label] : copyRandomList(head->random);
    }
    return node;
  }

 private:
  unordered_map<int, RandomListNode*> nodes_;
};

// Method 2
// Date: 2015-02
class Solution
{
public:
  RandomListNode *copyRandomList(RandomListNode *head)
  {
    if (head == NULL)
    {
      return NULL;
    }
    auto node = nodes[head->label];
    if (node == NULL)
    {
      node = new RandomListNode(head->label);
      nodes[head->label] = node;
      node->next = copyRandomList(head->next);
      node->random = copyRandomList(head->random);
    }
    return node;
  }

private:
  map<int, RandomListNode*> nodes;
};

// Method 1
// Date: 2015-02
struct Label
{
  Label(int label, RandomListNode* next) : label(label), next(next) {}
  friend bool operator< (const Label& a, const Label& b)
  {
    return a.label < b.label;
  }

  int label;
  RandomListNode* next;
};

class Solution
{
public:
  RandomListNode *copyRandomList(RandomListNode *head)
  {
    if (head == NULL)
    {
      return NULL;
    }
    auto node = nodes[Label(head->label, head->next)];
    if (node == NULL)
    {
      node = new RandomListNode(head->label);
      nodes[Label(head->label, head->next)] = node;
      node->next = copyRandomList(head->next);
      node->random = copyRandomList(head->random);
    }
    return node;
  }
  
private:
  map<Label, RandomListNode*> nodes;
};
