class Solution:
    def climbStairs(self, n: int) -> int:
        dp=[0]*(n+1);dp[0]=1;dp[1]=1
        for stairs in range(2,n+1):
            dp[stairs] = dp[stairs-2]+dp[stairs-1]
        return dp[n]