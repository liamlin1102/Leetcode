# 上面用 heap的方法
class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        # 把nums變成heap
        heapq.heapify(nums)
        # 若長度大於K，把最後一個踢掉
        while len(nums)>k:
            heapq.heappop(nums)
        # 把nums的物件給值
        self.nums = nums
        # 把length的物件給值
        self.length = k
    def add(self, val: int) -> int:
        if len(self.nums)<self.length:
            # 如果長度沒超過，把它塞進去
            heapq.heappush(self.nums,val)
        else:
            # 長度超過了，先賽進去然後把正確的值取出來
            # 不可以用heapreplace，因為它會顯取出來再丟進去，如果你取出來的值比賽進去的大那就出事了，所以要先賽
            heapq.heappushpop(self.nums,val)
        return self.nums[0]

# 別看　報立法
# class KthLargest:

#     def __init__(self, k: int, nums: List[int]):
#         nums.sort()
#         self.length = k
#         self.nums = nums[-k:]
#     def add(self, val: int) -> int:

#         if not self.nums:
#             self.nums.append(val)
#             return val
#         if val<=self.nums[0] and len(self.nums)==self.length:
#             return self.nums[0]
#         left = 0;right = len(self.nums)-1
#         while (right>=left):
#             mid = left+(right-left)//2
#             if self.nums[mid]>val:
#                 right = mid-1
#             else:
#                 left = mid+1
#         self.nums.insert(left,val)
#         if len(self.nums)>self.length:
#             self.nums.pop(0)
#         return self.nums[0]