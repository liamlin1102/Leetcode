# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# 這題的方式就是用K去找出要rotate幾次
class Solution:
    def rotateRight(self, head, k):
        if not head:
            return head
        # 我們要先知道多長才知道要迴轉幾次
        # 所以我們要先知道長度然後屬到那個長度，       
        cur= head
        length =1
        # 往後走抓長度
        while cur.next:
            cur = cur.next
            length+=1 
        # 這邊開始做題目，我們先找到最後。並且指定next到頭。就完成他的迴轉了，接下來找哪裡
        cur.next = head

        # 看他多多少，這邊不能直接用length-k，假設轉兩圈以上k>length就會出事，因此直接取lenrth - 餘數(代表到你一個停)
        k= length - (k%length)
        while k>0:
            cur=cur.next
            k-=1
        # 把它變成新的頭
        newhead = cur.next
        # 把尾巴斷掉
        cur.next=None
        return newhead
# 寫的比較不乾淨的版本，基本上原理跟上面的一樣
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        count = 0
        if k==0 or not head :return head
        cur_head = head 
        length = self.check_len(head)
        if k%length==0: return head
        elif k>length : k = k%length
        while  count<(length-k-1) :
            cur_head = cur_head.next
            count+=1
        prev_head =cur_head.next
        cur_head.next = None
        cur_head = prev_head 
        while cur_head.next :
            cur_head = cur_head.next
        cur_head.next = head
        return prev_head
    def check_len(self,head):
        count = 0
        cur = head
        while cur:
            count+=1
            cur = cur.next 
        return count
        
