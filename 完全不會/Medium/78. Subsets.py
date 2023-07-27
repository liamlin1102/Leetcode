# 解題思路,backtracking的原理就是把所有可能的情況列出來，就是數列中分成要跟不要依次往下拿
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        # 如果是空的直接傳空
        if not nums:return [[]]
        mergelist = [];ans =[];start_index=0
        # 跑遞迴
        self.recursion(nums,start_index,mergelist,ans)
        return ans
    def recursion(self,nums,start_index,mergelist,ans):
        # 用deep copy以免mergelist被修改
        deepcopy = mergelist.copy()
        # 管他什麼值都加進去，反正我全都要
        ans.append(deepcopy)
        # 跑回圈，管他的從頭到尾，條件進下一個遞迴再說啦
        for index in range(start_index,len(nums)):
            # 管他的加進去
            mergelist.append(nums[index])
            # 從下一個往下加，簡單說起來
            # nums = [1,2,3] 第一次 ans=[[]],index=0,num[index] = 1 start_index=0 進 rec,
            # nums = [1,2,3] 第二次 ans=[[],[1]],index=1,num[index] = 2 start_index=1 進 rec,
            # ...
            # 跳出至stack呈最上方呈現 nums = [1,2,3] ans=[[],[1],[1,2],[1,2,3]],index=0,num[index] = 1 start_index=0, 
            self.recursion(nums,index+1,mergelist,ans)
            # 此時要把mergelist裡面的 1 拿掉，才能製造2開頭的subset
            mergelist.pop()
    