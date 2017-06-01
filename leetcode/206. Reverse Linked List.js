// Copyright 2017 Qi Wang
// Date: 2017-06-01
// Method 2: traversal
const reverseList = head => {
  if (null === head) return head;
  let prev = null;
  while (null !== head) {
    const next = head.next;
    head.next = prev;
    prev = head;
    head = next;
  }
  return prev;
};

// Date: 2017-06-01
// Method 1: recursion
const reverseList = head => {
  let newHead;

  /**
   * @param {ListNode} node, a non-null ListNode
   */
  const reverseListIter = node => {
    // Reach the tail of the origin list
    if (null === node.next) {
      newHead = node;
    } else {
      const next = reverseListIter(node.next);
      next.next = node;
    }
    return node;
  };
  
  if (null === head) {
    return null;  // trivial case
  } else {
    // "newTail.next = null" is mandatory to make sure the new reversed list
    // will terminate when it's iterated
    reverseListIter(head).next = null;
    return newHead;
  }
};
