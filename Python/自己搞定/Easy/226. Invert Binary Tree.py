# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root == None:
            return 
        # 將左右節點互換
        root.left,root.right = root.right,root.left
        # 去Son Node 持續做
        self.invertTree(root.left)
        self.invertTree(root.right)
        return root 