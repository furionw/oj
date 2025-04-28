// Date: 2018-12-02
// This correct algorithm is designed by XH.
public class Solution {
  public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode pseudoHead = new ListNode(-1);
    ListNode node = new ListNode((l1.val + l2.val) % 10);
    pseudoHead.next = node;
    int carry = (l1.val + l2.val) / 10;
    l1 = l1.next;
    l2 = l2.next;
    // 9 -> 9 -> nil
    //      ^
    //      |
    //      l1
    // 1 -> nil
    //      ^
    //      |
    //      l2
    // -1 -> 0 -> nil
    //  ^    ^
    //  |    |
    //  h   node
    // carry = 1
    while (l1 != null && l2 != null) {
      ListNode newNode = new ListNode((l1.val + l2.val + carry) % 10);
      carry = (l1.val + l2.val + carry) / 10;
      node.next = newNode;
      node = newNode;
      l1 = l1.next;
      l2 = l2.next;
    }
    if (l1 != null){
      addRemains(l1, carry, node);
    } else {
      addRemains(l2, carry, node);
    }
    // -1 -> 0 -> 0 -> 1
    //  ^    ^
    //  |    |
    //  h   node
    // 是的，调用 addRemains 前后，node 始终指向“个位 0”，但是它的 next 发生了变化
    // 也就说，node 所指向的值（那个节点的next）发生了变化
    return pseudoHead.next;
  }

  public static void addRemains(ListNode l, int carry, ListNode node) {
    // 9 -> 9 -> nil
    //      ^
    //      |
    //      l
    // carry = 1
    // -1 -> 0 -> nil
    //       ^
    //       |
    //      node
    while (l != null) {
      ListNode newNode = new ListNode((l.val + carry) % 10);
      carry = (l.val + carry) / 10;
      node.next = newNode;
      node = newNode;
      l = l.next;
    }
    // 9 -> 9 -> nil
    //           ^
    //           |
    //           l
    // carry = 1
    // -1 -> 0 -> 0 -> nil
    //            ^
    //            |
    //           node
    if (carry != 0) {
      ListNode newNode = new ListNode(carry);
      node.next = newNode;
    }
    // -1 -> 0 -> 0 -> 1 -> nil
    //                 ^
    //                 |
    //                node
  }
}

// This incorrect algorithm is designed by XH.
class Solution {
  public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode pseudoHead = new ListNode(0);
    ListNode node = new ListNode((l1.val + l2.val) % 10);
    pseudoHead.next = node;
    int carry = (l1.val + l2.val) / 10;
    l1 = l1.next;
    l2 = l2.next;
    // 9 -> 9 -> nil
    //      ^
    //      |
    //      l1
    // 1 -> nil
    //      ^
    //      |
    //      l2
    // 0
    // ^
    // |
    // node
    // carry = 1
    while (l1 != null && l2 != null) {
      ListNode newNode = new ListNode((l1.val + l2.val + carry) % 10);
      carry = (l1.val + l2.val + carry) / 10;
      node.next = newNode;
      node = newNode;
      l1 = l1.next;
      l2 = l2.next;
    }
    carry = (l1 != null)? addRemains(l1, carry, node) : addRemains(l2, carry, node);
    // 0 -> 0 -> nil
    // ^
    // |
    // node
    // carry = 1
    if (carry != 0) {
      ListNode newNode = new ListNode(carry);
      node.next = newNode;
      // 0 -> 1 -> nil
      //      ^
      //      |
      //     node
    }
    return pseudoHead.next;
  }

  // 9 -> 9 -> nil
  //      ^
  //      |
  //      l
  // carry = 1
  // 0
  // ^
  // |
  // node
  public static int addRemains(ListNode l, int carry, ListNode node) {
    while (l != null) {
      ListNode newNode = new ListNode((l.val + carry) % 10);
      carry = (l.val + carry) / 10;
      node.next = newNode;
      node = newNode;
      l = l.next;
    }
    // 9 -> 9 -> nil
    //            ^
    //            |
    //            l
    // 0 -> 0 -> nil
    //      ^
    //      |
    //     node
    // carry = 1
    return carry;
  }
}

