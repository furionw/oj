class Solution {
  public ListNode reverseList(ListNode head) {
    if (head == null) {
      return null;
    }
    reverse(head).next = null;
    return newHead;
  }

  private ListNode reverse(ListNode curr) {
    if (curr.next == null) {
      return newHead = curr;
    }
    ListNode result = reverse(curr.next);
    result.next = curr;
    return curr;
  }

  private ListNode newHead;
}
