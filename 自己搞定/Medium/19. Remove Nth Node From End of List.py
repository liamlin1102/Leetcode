# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not  head.next:
            return 
        dic = {}
        count = 1
        curr = head
        while curr:
            dic[count],count,curr = curr,count+1,curr.next
        if n==1:
            dic[count-2].next = None
        elif count-1==n:
            head = head.next
        else:
            dic[count-n-1].next = dic[count-n+1]
        return head
    
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head.next:return

        slow =fast = head
        for _ in range(n):
            fast = fast.next
        if not fast: return head.next
        while fast.next:
            fast,slow = fast.next,slow.next
        slow.next = slow.next.next
        return head