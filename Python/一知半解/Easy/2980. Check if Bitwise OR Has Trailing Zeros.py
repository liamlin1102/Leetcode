class Solution:
    def hasTrailingZeros(self, nums: [int]) -> bool:
        flag = False
        for i in nums:
            intBin = bin(i)
            if (flag and intBin[-1]=="0"):
                return True 
            if(intBin[-1]=="0"):
                flag = True
        return False