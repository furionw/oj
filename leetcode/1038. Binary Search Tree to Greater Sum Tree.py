# Copyright 2019 Qi Wang
# Date: 2019-05-18
# Refer to: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/discuss/292052/Java-O(N)-Time-O(1)-Space-reverse-In-order-Traversal
# Time complexity O(N)
class Solution:
    pointer = None
    def bstToGst(self, root: TreeNode) -> TreeNode:
        if root is None:
            return None
        result = TreeNode(0)
        result.right = self.bstToGst(root.right)
        result.val = self.pointer.val + root.val if self.pointer is not None else root.val
        self.pointer = result
        result.left = self.bstToGst(root.left)
        return result

# Date: 2019-05-18
# Time complexity O(N^2)
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        return self.bstToGstCore(root, root)

    def bstToGstCore(self, node, root):
        if node is None:
            return None
        result = TreeNode(0)
        if node.left is not None:
            result.left = self.bstToGstCore(node.left, root)
        if node.right is not None:
            result.right = self.bstToGstCore(node.right, root)
        result.val = self.sumOfLargerValues(node.val, root)
        return result

    def sumOfLargerValues(self, val, node):
        if node is None:
            return 0
        sumOfLargerValues = self.sumOfLargerValues(val, node.right)
        if val <= node.val:
            sumOfLargerValues += node.val + self.sumOfLargerValues(val, node.left)
        return sumOfLargerValues
