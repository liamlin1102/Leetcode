class Solution:
    # def removeElement(self, nums: List[int], val: int) -> int:
    #     # ans,slow,fast = len(nums),0,1
    #     # while slow<len(nums):
    #     #     if nums[slow]==val:
    #     #         nums.pop(slow)
    #     #         ans-=1
    #     #     else:
    #     #         slow+=1
    #     # return ans
    # 本題是排好的list，前後不一樣就交換
    def removeElement(self, nums: List[int], val: int) -> int:
        count = 0
        for i in range(len(nums)):
           if nums[i] != val:
                nums[count] = nums[i]
                count += 1

        return count