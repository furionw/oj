// Copyright 2019 Qi Wang
// Date: 2019-04-01
object Solution {
  def swapPairs(head: ListNode): ListNode = {
    if (head == null || head.next == null) {
      head
    } else {
      val newHead = head.next
      head.next = swapPairs(newHead.next)
      newHead.next = head
      newHead
    }
  }
}
