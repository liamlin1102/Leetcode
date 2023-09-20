# 這題有點難，首先我們就是要回傳一個deepcopy的 原始版本，最簡單的方法就是遍歷原來的Node，並且把新舊的用map對一起，同時當作檢查點，如果回到了頭代表這一路已經走到底就可以往上換下一路
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        # 先設定一個map存值，順邊當記錄點
        visitded={}
        # 跑遞迴啦
        def dfs(node,visitded):
            # 如果他是None 代表他只向死胡同，這並不符合無向圖的邏輯，指有可能一開始就啥都沒有，回傳None
            if not node :return
            # 先用現在的val新增一個新的Node
            ans = Node(node.val) 
            # 把舊的node當 key，把新的node當value
            visitded[node] = ans
            # 跑回圈，往下找，這邊有點像linke list，注意pointer的概念就好
            for neighbor in node.neighbors:
                # 如果他在visited代表我們遇到過了，直接把他家進去我們鄰居的list就好
                if neighbor in visitded:
                   ans.neighbors.append(visitded[neighbor])
                # 如果不在，代表這東西完全是新的，我們要在往這個新的neighbor再往下找，因此用 tail recrusion 去跑 dfs
                else:
                    ans.neighbors.append(dfs(neighbor,visitded))
                    回傳達案
            return ans
        return dfs(node,visitded)
# 這比較爛，但原理差不多，別館這寫法。
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        def dfs(node,visitded):
            if not node :return
            ans = Node(node.val) 
            visitded[node.val] = ans
            for neighbor in node.neighbors:
                if neighbor.val in visitded:
                   ans.neighbors.append(visitded[neighbor.val])
                else:                  
                    ans.neighbors.append(dfs(neighbor,visitded))              
            return ans
        visitded={}
        ans = dfs(node,visitded)
        return ans