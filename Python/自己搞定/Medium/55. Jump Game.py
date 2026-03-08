class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxIndex = 0 
        index = 0
        while index <= maxIndex and index<len(nums):
            maxIndex = max(nums[index]+index,maxIndex)
            index+=1
            if(maxIndex>=len(nums)-1):
                return True 
        return False
        