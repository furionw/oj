#include <iostream>
#include <functional>

using namespace std;

struct ListNode {
  ListNode(int v, ListNode* next = nullptr) : val(v), next(next) {}
  int val;
  ListNode* next = nullptr;
};

void Insert(ListNode* node, int val) {
  if (node == nullptr) return;
  node->next = new ListNode(val, node->next);
}

ListNode* Remove(ListNode* node,
                 function<bool(ListNode*)> functor) {
  if (node == nullptr) {
    return nullptr;
  } else if (functor(node)) {
    auto next = node->next;
    delete node;
    return Remove(next, functor);
  } else {
    node->next = Remove(node->next, functor);
    return node;
  }
}

void Print(ListNode* node) {
  for (; node != nullptr; node = node->next) {
    cout << node->val << " ";
  }
  cout << endl;
}

int main() {
  auto head = new ListNode(1);
  Insert(head, 2);
  Insert(head, 3);
  Insert(head, 4);
  Print(head);
  Print(Remove(head, [](ListNode* node) {
    return node != nullptr && node->val % 2 == 0;
  }));
  Print(Remove(head, [](ListNode* node) {
    return node != nullptr && node->val == 1;
  }));
}