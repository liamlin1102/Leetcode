class Solution:
    def CountBits(self,num:int):
        count = 0
        while(num>0):
            count+=num&1
            num>>=1
        return count
    def checkSort(self,nums):
        for i in range(1,len(nums)):
            if(nums[i]<nums[i-1]):
                return False
        return True
    def canSortArray(self, nums) -> bool:
        temp = nums
        if(self.checkSort(nums)):
            return True
        bitList = [0]*len(nums)
        bitList[0] = self.CountBits(nums[0])
        prevBit = bitList[0]
        prevIndex = 0        
        for i in range(1,len(nums)):
            bitList[i]=self.CountBits(nums[i])
            if(bitList[i]!=prevBit):
                nums[prevIndex:i] = sorted(nums[prevIndex:i])
                prevBit = bitList[i]
                prevIndex = i
        nums[prevIndex:] = sorted(nums[prevIndex:])
        return self.checkSort(nums)