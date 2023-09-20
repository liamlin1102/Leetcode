# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# subtree 的邏輯是指該子樹必須所有子樹都一樣
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:       
        if not root:
            return False  
        # 查看兩個是否相等
        if self.isequal(root,subRoot):
            return True
        # 不論相等不相等，都要往下做，因為如果上面觸發了，回傳false 但真正的子樹在下方，那就會假失敗
        lbool = self.isSubtree(root.left,subRoot)
        # 先看左邊 左邊找到就回傳了
        if lbool :
            return True
        # 再看右邊，右邊找到就回傳
        rbool = self.isSubtree(root.right,subRoot)
        if rbool :
            return True
        # 沒有 0 
        return False

            
    def isequal(self,root,subRoot):      
        fbool =False     
        # 看主節點跟subtree是否都是終點
        if (not root) and (not subRoot):
            return True
        # 有一個到終點一個沒到代表他們肯定不相等
        if (not root) or (not subRoot):
            return False
        # 查看他們是否相等
        if root.val == subRoot.val:
            # 若相等往左子樹去查看
            fbool = self.isequal(root.left,subRoot.left)
            # 不相等跳出
            if not fbool:
                return False
            # 若相等往右子樹去查看          
            fbool = self.isequal(root.right,subRoot.right)
            if not fbool:
                return False
            return True
        # 不相等當然直接跳出
        else:
            return False 
        
#方法2 跟鬼一樣 
# class Solution:
#     很簡單直接把她展開成字串 看有沒有contain在裡面 真的牛逼
#     def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
#         string_s = self.traverse_tree(s)
#         string_t = self.traverse_tree(t)
#         if string_t in string_s:
#             return True
#         return False
    
    
#     def traverse_tree(self, s):
#         if s:
#             return f"#{s.val} {self.traverse_tree(s.left)} {self.traverse_tree(s.right)}"
#         return None

# 真方法2 上面是邪教 簡潔版
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        if not s: 
            return False
        if self.isSameTree(s, t): 
            return True
        return self.isSubtree(s.left, t) or self.isSubtree(s.right, t)

    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p and q:
            return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        return p is q