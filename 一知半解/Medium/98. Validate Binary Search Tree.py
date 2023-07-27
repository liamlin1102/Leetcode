# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# 關鍵每一個左節點的值都不能比母節點高()

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def retnode(root: Optional[TreeNode],min_node:int,max_node:int)->bool:
            if root==None:
                return True
            lbool = True
            rbool = True
            # 看左子樹
            if root.left :
                # 若最小值存在，並且在左子樹，符合BST原則 root.left.val 必定是最小值~root.val
                if(min_node!=None) :
                    lbool =  (root.val>root.left.val)and(root.left.val>min_node)
                # 若最小值不存在(代表第一次或是在最左邊的子樹)    
                else:
                    lbool = (root.val>root.left.val)
            # 看右子樹
            if root.right:
                # 若最大值存在，並且在右0子樹，符合BST原則 root.left.val 必定是root.val~最大值
                if(max_node!=None) :
                    rbool =  (root.val<root.right.val)and(root.right.val<max_node)
                 # 若最大值不存在(代表第一次或是在最右邊的子樹)                      
                else:
                    rbool = (root.val<root.right.val)
            # 只要有一邊不符合BST的原則 回傳False
            if(not lbool)or(not rbool):
                return False
            # recrusion
            ansl= retnode(root.left,min_node,root.val)
            ansr= retnode(root.right,root.val,max_node)
            # 要全部都是true否則失敗
            if (ansl)and(ansr):
                return True
            return False
        if root ==None:
            return False
        ans = retnode(root,None,None)
        return ans
    #  精美寫法，這題解法很簡單，就下去看所有BST是否都滿足原理
    
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        # 寫一個recrusion
        def helper(node, low, high):
            if not node:
                return True
            # 如果不是val比低大 比高小
            if not (low < node.val < high):
                return False
            # 關鍵思路，若往左走，高點的數值會被更新，原因是要符合BST一定要左邊比中間小
            # 關鍵絲路，若往右走，低點的數值會被更新，原因是要符合BST一定要右邊比中間大
            # 為了防止上下層的關西,導致這層符合BST但上上層不符合，因此邊界要被傳遞下去
            # 因此下面就是如果下一個比較為當前的left 代表目前檢查leftsubtree 因此 更新高點為現在的val 反之更新低點 
            return helper(node.left, low, node.val) and helper(node.right, node.val, high)
        
        return helper(root, -inf, inf)