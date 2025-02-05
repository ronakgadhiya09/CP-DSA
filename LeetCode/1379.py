# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def dfs(self,node1: TreeNode,node2: TreeNode,target: TreeNode) -> TreeNode:

        if not node1:
            return node2

        if node1==target:
            return node2

        left = self.dfs(node1.left,node2.left,target)
        if left:
            return left
        
        right = self.dfs(node1.right,node2.right,target)
        return right

    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        return self.dfs(original,cloned,target)
