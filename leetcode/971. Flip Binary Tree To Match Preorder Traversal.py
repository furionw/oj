# Copyright 2019 Qi Wang
# Refer to: https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/discuss/214216/JavaC%2B%2BPython-DFS-Solution
class Solution:
    def flipMatchVoyage(self, root, voyage):
        """
        :type root: TreeNode
        :type voyage: List[int]
        :rtype: List[int]
        """
        self.idx = 0
        res = []
        def dfs(root):
            if not root:
                return True
            elif root.val != voyage[self.idx]:
                return False
            self.idx += 1
            if root.left and root.left.val != voyage[self.idx]:
                res.append(root.val)
                root.left, root.right = root.right, root.left
            return dfs(root.left) and dfs(root.right)
        return res if dfs(root) else [-1]
