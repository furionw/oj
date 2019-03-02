# Copyright 2019 Qi Wang
# Date: 2019-03-02
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        if not nums:
            return None
        idx = nums.index(max(nums))
        root = TreeNode(nums[idx])
        if idx > 0:
            root.left = self.constructMaximumBinaryTree(nums[0: idx])
        root.right = self.constructMaximumBinaryTree(nums[idx + 1:])
        return root
