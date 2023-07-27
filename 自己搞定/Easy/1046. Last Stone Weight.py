import heapq
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        #由於這題是要找出最大的石頭，python沒辦法做出Max heap 故把所有的數字加入負數
        maxstones = [-_ for _ in stones]
        heapq.heapify(maxstones)
        # 當這裡面超過1個以上
        while maxstones and len(maxstones)>1:
            # 先取出來(最大)
            max1 = -(heapq.heappop(maxstones))
            # 第二個取出來(第二大)
            max2 = -(heapq.heappop(maxstones))
            # 相減
            dis = max1 - max2
            # 不是0就丟回去
            if dis!=0:
                heapq.heappush(maxstones,-dis)
        # 最後再檢查一次，如果裡面有東西回傳那個值
        if len(maxstones)!=0:

            return -maxstones[0]
        # 沒有救回傳0
        else:
            return 0