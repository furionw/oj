class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        return self.buildTreeIter(preorder, 0, len(preorder), inorder, 0, len(inorder))

    def buildTreeIter(self, preorder, p_begin, p_end, inorder, i_begin, i_end):
        if p_begin >= p_end or p_begin >= len(preorder):
            return None
        length = inorder.index(preorder[p_begin]) - i_begin;
        node = TreeNode(preorder[p_begin])
        node.left = self.buildTreeIter(preorder, p_begin + 1, p_begin + length + 1, \
                inorder, i_begin, i_begin + length)
        node.right = self.buildTreeIter(preorder, p_begin + length + 1, p_end, \
                inorder, i_begin + length + 1, i_end)
        return node

Solution().buildTree([1, 2, 4, 7, 3, 5, 6, 8], [4, 7, 2, 1, 5, 3, 8, 6])
Solution().buildTree([1, 2, 3, 4, 5], [1, 2, 3, 4, 5])

