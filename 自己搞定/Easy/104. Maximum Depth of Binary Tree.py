# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# recrusion 的原理就是不斷展延 self.maxDepth(root.left) = 1 + self.maxDepth(root.left.left)(因為我定應ledpth = 1+self.maxDepth(root.left))
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if(root==None):
            return 0
        # 透過recrusion 不斷累加1回來來確定層數幾層
        ldepth = 1+self.maxDepth(root.left)
        rdepth = 1+self.maxDepth(root.right)
        if ldepth>rdepth:
            ans = ldepth
        else :
            ans = rdepth
        return ans
