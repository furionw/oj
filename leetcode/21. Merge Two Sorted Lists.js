// Copyright 2018 Qi Wang
// Date: 2018-06-05
const mergeTwoLists = (l1, l2) => {
  const dummy = ListNode(0);
  let tail = dummy;
  while (l1 && l2) {
    if (l1.val <= l2.val) {
      tail.next = l1;
      l1 = l1.next;
    } else {
      tail.next = l2;
      l2 = l2.next;
    }
  }
  tail.next = l1 ? l1 : l2;
  return dummy.next;
};
