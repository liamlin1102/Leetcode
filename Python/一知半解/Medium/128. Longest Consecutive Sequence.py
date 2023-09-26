class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        setNum = set(nums);maxLen=1;longestLen=1;step=1
        if len(setNum)<=1:
            return len(setNum)
        for num in setNum:
            if num-1 not in setNum:
                while num+step in setNum:
                    step+=1
                longestLen = max(longestLen,step)
                step = 1
        return longestLen