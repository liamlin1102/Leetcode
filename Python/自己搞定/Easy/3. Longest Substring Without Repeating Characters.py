import heapq
class Solution:
    def numberGame(self, nums: int):
        heapq.heapify(nums)
        answer = []
        while(len(nums)>0):
            smallone =heapq.heappop(nums)
            smalltwo = heapq.heappop(nums)
            answer.append(smalltwo)
            answer.append(smallone)
        return answer
