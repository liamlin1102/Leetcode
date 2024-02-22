class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        answer = nums[0]
        minNum = 51
        minNum2 = 51
        for i in range(1,len(nums)):
            if(nums[i]<minNum):
                minNum2,minNum = minNum,nums[i]
            elif(nums[i]<minNum2):
                minNum2 = nums[i]
        return answer+minNum+minNum2
            