# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# https://leetcode.com/problems/balanced-binary-tree/solutions/2011001/o-n-time-beats-99-97-memory-speed-0ms-may-2022/
class Solution(object):
    def isBalanced(self, root):
            
        def check(root):
            if root is None:
                return 0
            left  = check(root.left)
            right = check(root.right)
            if left == -1 or right == -1 or abs(left - right) > 1:
                return -1
            return 1 + max(left, right)
            
        return check(root) != -1
    
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        # 求多深
        def getDepth(root) ->int:
            # 一樣如果是終點 該終點不算
            if not root:
                return 0
            # 遞迴
            ldepth = getDepth(root.left)
            # 如果左邊深度不是-1
            if (ldepth==-1):
                return -1
            # 遞迴
            rdepth = getDepth(root.right)
            # 如果右邊深度不是-1
            if (rdepth==-1):
                return -1
            # 如果兩邊深度差超過1
            if abs(ldepth-rdepth)>1:
                return -1
            # 看哪個大用哪個最大的回傳 深度+1(因為結束了深度多一層)
            elif ldepth>rdepth:
                return 1+ldepth
            else:
                 return 1+rdepth
        if not root:
          return  True
        # 正常狀況下深度會被recrusion一直往後+，不可能是負的，除非發現兩邊深度超過1。才會回傳-1，因此該狀況代表root tree is not a balance tree
        if getDepth(root)==-1:
            return False
        # 一切正常管它深度多少 船正確
        else:
            return True
        
class Solution(object):
    def isBalanced(self, root):
        return (self.Height(root) >= 0)
    def Height(self, root):
        if root is None:  return 0
        leftheight, rightheight = self.Height(root.left), self.Height(root.right)
        if leftheight < 0 or rightheight < 0 or abs(leftheight - rightheight) > 1:  return -1
        return max(leftheight, rightheight) + 1
