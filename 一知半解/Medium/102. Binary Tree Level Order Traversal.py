# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # 寫一個遞迴
        def recrusion(node) ->  List[List[int]]:  
            # 如果是none 返回空值
            if node==None:
                return []
            #解題思路，一個NODE會有兩個SON NODE，只要把左節點跟右節點的list取出來並且最後相加 
            ltree = []
            rtree = []   
            #左邊有值，加進左邊的NODE list    
            if node.left!=None:
                ltree.append([node.left.val])
            #右邊有值，加進右邊的NODE list    
            if node.right!=None:
                rtree.append([node.right.val])
            # 重複運算左邊跟右邊的node 不斷的去把下面Son node的值放進list裡面並且累加回來
            ltree+=recrusion(node.left)
            
            rtree+=recrusion(node.right)       
            
            # 把同一層的加在一起
            if (len(ltree)>len(rtree)):
                num=len(rtree)
            else:
                num=len(ltree)
                ltree+=rtree[num:]
            for depth in range(num):
                ltree[depth]+=rtree[depth]              
            return ltree
        if root==None:
            return []
        
        ans = [[root.val]]
        ans += recrusion(root)
        return ans
        # 精美寫法 空間複雜度可能會爆炸. 看需要O(N)還是空間?
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        # 把root放進list裡面，用queue的方式跑BFS
        queue = [root]
        next_queue = []
        level = []
        result = []
        # 這邊思路是這樣，只要queue有東西，代表該queue都是同一個depth的subtree，因此解題方式就是把下一層拆出來的(left and right)通通丟到另一個queue裡面
        # 如果queue有東西，就繼續跑
        while queue:
            # 針對該queue進行跑
            for root in queue:
                # 把這層的val放進level裡
                level.append(root.val)
                # 看有沒有左右邊 有的畫丟到下一層的queue
                if root.left:
                    next_queue.append(root.left)
                if root.right:
                    next_queue.append(root.right)
            # loop end ，把所有的東西丟到result 的方式
            result.append(level)
            # 還原
            level = []
            # 把下一層的東西丟回給queue以免while loop end
            queue = next_queue
            # 復原
            next_queue = []
        
        return result
