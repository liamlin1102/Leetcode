import heapq
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class PriorityListNode(ListNode):
    def __lt__(self, other):
        return self.val < other.val
 
class Solution:
    def mergeKLists(self, lists: [[ListNode]]) -> [ListNode]:
        pq = []
        for listt in lists:
            while(listt):
                pL = PriorityListNode(listt.val)
                heapq.heappush(pq,(pL.val,pL))
                listt = listt.next
        start = heapq.heappop(pq)[1]     
        if (not start):
            return None
        answer = start      
        while(pq):
            start.next = heapq.heappop(pq)[1] 
            start = start.next 
        start.next = None
        return answer
            
