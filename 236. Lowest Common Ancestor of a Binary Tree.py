# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 這題巨難 完全看答案慢慢念

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        return self.getTree(root,p,q)

    def getTree(self,root:'TreeNode', p: 'TreeNode', q: 'TreeNode'):
        # 到底回傳None
        if (not root):
            return 
        # 發現只要找到一個值就回傳root 這邊傳啥一點都不重要 就是要讓他不是None
        if (root.val ==p.val) or  (root.val ==q.val):
            return root
        # 跑遞迴 讓他下去找邊界在哪
        ltree = self.getTree(root.left,p,q)
        rtree = self.getTree(root.right,p,q)
        # 如果兩個都有值 代表此時左右子樹內同時有包含邊界，此時該root 就是parent node 
        if (ltree)and(rtree):
            return root 
        # 如果只有一個有值 你跑完了整個都只有一個有值 這就是重點了 根據題目，兩個值一錠都在tree裡面，因此另一個值到底在哪 只有可能在19行的下面的子樹
        # 因為被提早回傳導致沒找到，這代表該子樹的parent node 就是被回傳的那個值 因此只有一個值的狀況就是回傳有的那個值
        if(ltree):
            return ltree
        else:
            return rtree
