// Copyright 2019 Qi Wang
// Date: 2019-03-13
object Solution {
  def maxDepth(root: TreeNode): Int = root match {
    case null => 0
    case _ => math.max(maxDepth(root.left), maxDepth(root.right)) + 1
  }
}
