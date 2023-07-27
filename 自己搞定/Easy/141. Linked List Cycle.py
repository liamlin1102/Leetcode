class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # 建一個dic 來查值
        dic = {}
        while head and not head in dic :
            dic[head]=0
            head = head.next
        return head in dic
    # 比較好的寫法，快慢指針
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # 定義一個指針快跟慢
        fastptr = head
        slowptr = head
        # 當快指針不是空的同時快指針下一個也不是空的(很簡單 反正快指針跑比較快，理論上如果該Linkedlist會cycle代表短的一定部會碰到None)
        while fastptr is not None and fastptr.next is not None:
            # 曼的走一步快地走兩步
            slowptr = slowptr.next
            fastptr = fastptr.next.next
            # 看是否相等   
            if slowptr == fastptr:
                return True
        return None