class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # 用dic把出現的次數數進去
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        # 做出一個heap
        heap = []
        # 把dic的key value做成list(num,count)
        for num, count in freq.items():
            # 如果長度比我們要取的總數字小
            if len(heap) < k:
                # 無條件加進去
                heapq.heappush(heap, (count, num))
            # 如果長度已經夠了，那我們就要檢查到底我們目前的次數是多還是少，如果比最小的大
            # 有兩種可能，1只比最小的還大2.不只比最小的還大
            # 這樣實作很麻煩，所以我們用heap的特性會自己找到正確的位置
            elif count > heap[0][0]:
                # 把最小的取出來
                heapq.heappop(heap)
                # 把較大的塞進去
                heapq.heappush(heap, (count, num))
        # 跑個迴圈求答案吧
        return [num for count, num in heap]