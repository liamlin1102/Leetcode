# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# 刪除掉重複項，這題不難，難在怎麼重製頭。
# 這題很吃Linkedlist的概念，要記得，LinkedList重點就是調整next以及如果頭會改變要用前指針

def deleteDuplicates(self, head: ListNode) -> ListNode:
    dummy_head = ListNode(next=head)
    prev, cur = dummy_head, head #設定一個前指針來指向可能變動的值
    # 這題做法很簡單，只要發現有重複就把代替head檢測的一直往下走，直到cur.val!=cur.next.val，跳出迴圈，這時將前指針的next給到不重複的值(next)\
    # 要記得LinkedList就是拼圖，你要把重複的去掉，那你就要先把重複的前指針存起來，方便你去跟後面的拼，但開頭沒有前指針啊，因此我們才會用前指針做一個prev出來
    # 如果一開場就被提換掉開頭，此時不管幾次prev.next都會連接到，同時dummy_head.next也都會跟著連接，讓我們答案能傳回
    # 如果沒有一開賞就被換，那麼我們prev就會往後走，變成真正的原始Node的前指針
    # 如果沒重複就同時移動，prev跟cur
    while cur and cur.next:
        if cur.val != cur.next.val:
            # If there's no duplicate,
            # move prev and cur one step forward
            prev, cur = cur, cur.next #沒重複就同時移動，prev跟cur
        else:
            # If there're duplicates,
            # iterate cur to the last duplicate nodes,
            # 重複的話就一直找 直到next跟cur不相等
            while cur.next and cur.val == cur.next.val:
                cur = cur.next
            # 此時cur是要被丟棄的 next才是正確，把前指針跟next接上
            # and jump over the duplicates
            prev.next = cur.next
            cur = cur.next
    
    return dummy_head.next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:return head
        cur = head;prevcur=ans=ListNode(0)
        ans.next =head
        while cur and cur.next :
            if cur.val == cur.next.val:
                while cur and cur.next and cur.val==cur.next.val:
                    cur = cur.next
                cur = cur.next
                prevcur.next = cur
            else: 
                prevcur = prevcur.next
                cur = cur.next 
        return ans.next


