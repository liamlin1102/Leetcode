# 
class Solution:
    def findMin(self, nums):
        left, right = 0, len(nums)-1            
        while left < right:
            mid = (left + right) // 2                   
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid
        return nums[left]

    # def findMin(self, nums: List[int]) -> int:
    #     if len(nums)==2:
    #         return min(nums[0],nums[1])
    #     if len(nums)==1:
    #         return nums[0]
    #     left = 0;right = len(nums)
    #     mid =(right-left)//2
    #     leftmin = self.findMin(nums[:mid])
    #     rightmin = self.findMin(nums[mid:])
    #     if leftmin>rightmin:
    #         return rightmin
    #     else:
    #         return leftmin
#
    # def findMin(self, nums: List[int]) -> int:
    #     low = 0
    #     high = len(nums) - 1
    #     while low <= high:
    #         mid = low + (high - low) // 2
    #         ele = nums[mid]
    #         if ele > nums[high]:
    #             low = mid + 1
    #         elif mid == 0 or nums[mid - 1] > nums[mid]:
    #             return nums[mid]
    #         else:
    #             high = mid - 1