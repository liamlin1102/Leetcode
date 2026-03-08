class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0]*(target+1)
        dp[0] = 1 ##代表剛好可被換掉，是一次
        for money in range(1,target+1):
            count = 0
            for num in nums:
                if money >= num:
                    count += dp[money-num]
            dp[money] = count
        return dp[-1]