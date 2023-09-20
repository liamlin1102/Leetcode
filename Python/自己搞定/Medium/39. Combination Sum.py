# 解題思路，我的寫法想法是，直接把每一種可能加總道等於會超過，如果加起來的值超過代表可以跳過
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
            ans=[];sublist=[];start_index=0
            self.recrusion(candidates,target,start_index,sublist,ans)
            return ans
    def recrusion(self,candidates,diffnum,start_index,sublist,ans):
        # 如果他們相減後等於0
        if diffnum == 0:
            # 加進去
            deepcopylist = sublist.copy()
            ans.append(deepcopylist)
        # 代表還要找東西扣
        elif diffnum>0:
            # 往下找，從頭開始因為有可能直接兩個自己結束
            for index in range(start_index,len(candidates)):
                # 先加
                sublist.append(candidates[index])
                diffnum-=candidates[index]
                # 講一下細節 假設是 candidates = [2,5,2,1,2], target = 5
                # 那我做到[2,2,2]會跳出，此時會是[2,2]往下一個迴圈，就會找到[2,2,5]
                self.recrusion(candidates,diffnum,index,sublist,ans)
                # 跳出代表找到了或是太小了，反正都加到ans裡面了
                sublist.pop()
                diffnum+=candidates[index]
# 比較好的寫法
# 思路，先排序整個co
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort(reverse=True)
        n = len(candidates)
        res = []
        
        def backtracking(idx, t, curr):
            if t == 0:
                res.append(curr[:])
            
            for i in range(idx, n):
                if t >= candidates[i]:
                    backtracking(i, t-candidates[i], curr + [candidates[i]])
        
        backtracking(0, target, [])
        return res