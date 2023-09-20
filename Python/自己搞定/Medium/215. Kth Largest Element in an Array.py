# 這題規定複雜度要O(n)，找出第幾大的數字
import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # 製作一個nums的 min heap
        heapq.heapify(nums)
        # 如果長度是大於我們要的數字就把東西丟出去
        while len(nums)>k:
            heapq.heappop(nums)
        # 這樣第一個就肯定是第K大的
        return nums[0]


# 這方法超簡單，排序後直接找倒數幾個
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums.sort()
        return nums[-k]