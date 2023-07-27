class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums)==1:return nums[0]
        elif len(nums)==2 or len(nums)==3:return max(nums)
        dp= [0]*(len(nums)-1)
        dp2 = dp.copy()
        for index in range(len(nums)-1):
            if index == 0:
                dp[0] = nums[0]
                dp2[0] = nums[1]
            elif index == 1:
                dp[1] = max(nums[0], nums[1])
                dp2[1] = max(nums[1], nums[2])
            else:
                dp[index] = max(dp[index-1],nums[index]+dp[index-2])
                dp2[index] = max(dp2[index-1],nums[index+1]+dp2[index-2])
        print(dp)
        print(dp2)
        return max(dp2[-1] , dp[-1])

class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def simple_rob(nums, i, j):
            rob, not_rob = 0, 0
            for idx in range(i, j):
                num = nums[idx]
                rob, not_rob = not_rob + num, max(rob, not_rob)
            return max(rob, not_rob)
        
        if not nums:
            return 0
        elif len(nums) == 1:
            return nums[0]
        else:
            n = len(nums)
            return max(simple_rob(nums, 1, n), simple_rob(nums, 0, n-1))