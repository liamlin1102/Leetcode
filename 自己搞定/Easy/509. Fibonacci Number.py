# 費式
class Solution:
    def fib(self, n: int) -> int:
        # 數值小於2 回傳自身
        if n<2:return n
        # 紀錄一下，前兩個沒辦法算手填
        nums=[0,1]
        for index in range(2,n+1):
            # 沿途算並加進去
            nums.append(nums[index-1]+nums[index-2])
        return nums[n]
class Solution:
    def fib(self, n: int) -> int:
        # 一樣小於2 回傳自身
        if n<2:return n
        # 給一個範圍放值
        dp=[0]*(n+1)
        def recrusion(n):
            # 跑遞迴
            if(n==0 or n==1):return n
            # 如果有值就取值別算
            if dp[n]!=0:
                return dp[n]
            # 跑遞迴
            dp[n]=recrusion(n-1)+recrusion(n-2)
            # 最後記得回傳
            return dp[n]
        recrusion(n)
        return dp[n]