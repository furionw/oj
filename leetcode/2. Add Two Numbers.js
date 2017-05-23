// Copyright 2017 Qi Wang
// Date: 2017-05-23
const addTwoNumbers = (l1, l2) => {
  /**
   * @param {ListNode} l
   * @param {int} carry
   * @return {ListNode}
   */
  const addOneNumber = (l, carry) => {
    if (null === l) {
      return 1 === carry ? new ListNode(1) : null;
    } else if (0 === carry) {
      return l;
    } else {
      const sum = l.val + carry;
      const result = new ListNode(sum % 10);
      result.next = addOneNumber(l.next, Math.floor(sum / 10));
      return result;
    }
  };

  /**
   * @param {ListNode} l1
   * @param {ListNode} l2
   * @param {int} carry
   * @return {ListNode}
   */
  const addTwoNumbers = (l1, l2, carry) => {
    if (null !== l1 && null !== l2) {
      const sum = l1.val + l2.val + carry;
      const result = new ListNode(sum % 10);
      result.next = addTwoNumbers(l1.next, l2.next, Math.floor(sum / 10));
      return result;
    } else {
      return addOneNumber(null !== l1 ? l1 : l2, carry);
    }
  };

  return addTwoNumbers(l1, l2, 0);
};
