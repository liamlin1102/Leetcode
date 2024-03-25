# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
#  此題解題思路，比值小的點刪除後，只需考慮右節點，因為BST的特性根本不用管左子樹，你都不在範圍內 怎麼可能左子樹在= =
class Solution:
    def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
        if root==None :
            return 
        # 小於範圍
        if low>root.val:
            # 右邊沒東西不管左邊 一律刪光光
            if (root.right==None):
                return 
            # 有東西跑遞迴進去檢查，是否右子樹裡面是正常的
            return self.trimBST(root.right,low,high)  
        #大於範圍   
        elif high<root.val:
            # 左邊沒東西不管右邊 一律刪光光
            if (root.left==None):
                return 
            # 有東西跑遞迴進去檢查，是否左子樹都是正常
            return self.trimBST(root.left,low,high)
        # 跑遞迴 以免值本身沒有刪除不繼續處理
        root.left = self.trimBST(root.left,low,high)
        root.right = self.trimBST(root.right,low,high)
        return root 
                 