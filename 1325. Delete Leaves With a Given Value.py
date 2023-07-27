# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    # https://leetcode.com/problems/delete-leaves-with-a-given-value/solutions/526084/python-90-short-6-lines-and-easy-explained/
    def removeLeafNodes(self, root: TreeNode, target: int) -> TreeNode:
        if root:
            root.left = self.removeLeafNodes(root.left, target)
            root.right = self.removeLeafNodes(root.right, target) 
            if root.val == target and not root.left and not root.right:
                root = None
        return root 

class Solution:
    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        if not root:
            return None
        # 如果發現是要刪除的值並且左右沒東西符合Leafs node
        if (root.val==target)and(not root.left)and(not root.right):
        # 把tree變成None
            return None
        # 往下做
        root.left,root.right = self.removeLeafNodes(root.left,target),self.removeLeafNodes(root.right,target)
        # 做完再檢查，如果我本身是要刪除的值並且上面把原本的subtree給變成None代表我自身變成leafs node 再次刪除(又再一次也無所謂因為此時會回傳None回去，這時因為recrusion會回到16行，會再次觸發18行)
        if (root.val==target)and(not root.left)and(not root.right):
            return None
        return root 