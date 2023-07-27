# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# 透過inorder traveler 可以讓整個BST的array 呈現排序 
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        def recrusion(root: Optional[TreeNode])->list(int):
            #  左邊右邊沒東西的時候回傳值
            if (not root.left) and (not root.right):
                return [root.val]
            ans = []
            # root.left有東西，去左邊跑並且把最下面的值加回來
            if (root.left):
                ans+=(recrusion(root.left))
            # 把root加回來
            ans+=([root.val])
            # root.right有東西，去右邊把最下面的值加回來
            if (root.right):
                ans+=(recrusion(root.right))
            return ans
        ans = recrusion(root)
        ans_num = ans[k-1]
        return ans_num
    # 哦幹 有Stack可以用... 用LIFO 去解題 應該是吧?
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        n=0
        stack=[]
        cur=root
        # 死媽寫法= = 
        # 思路是，我透過LIFO的原理往下找，一開始把整棵樹塞進去，然後換塞左邊，這樣他就會呈現(中，左，佐佐，佐佐佐,.....)，這裡面沒有任何right subtree
        # 這邊終於懂定義了，為啥要同時檢查cur 和stack 因為如果cur是最後的right subtree is null 所以stack只要有值 我們利用LIFO的原理,一值把最下面的子樹提出來 就會符合由小到大的特性
        while cur or stack :
            # 只要他還有佐子樹就一路往下加stack
            while cur :
                stack.append(cur)
                cur=cur.left       
            # 他就是最後一個取出來，根據INORDER 的原理他肯定是最小值(最左)
            cur=stack.pop()
            # 看是不是答案
            n +=1
            if n==k :
                return cur.val
            # 這邊也是，把她當右邊來解因為你left subtree沒東西不代表 rightsubtree沒東西 (左->中->右)
            cur = cur.right
            