# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head :
            return head
        # 關鍵，複製一份下來，解linked list的題目的時候不要看變數名稱去想它代表的pointer是什麼
        # 這邊copylist實際上指向的pointer跟head一樣，那這邊如果我們定義copylist.next那就會跟著定義到head.next
        # 但如果是重新定義copylist那只是改變copylist這個數值指向的pointer，此時copylist跟head就為不同的變數，但如果對他的next重新定義，就會一併定義同一個pointer的next
        copylist = head
        # 這邊放我們reverse的物件，由後往前推所以給定None
        prev =None
        # 當複製的裡面還有值時
        while  copylist:
            # 把第一個值跟後面的sublist分開，並且把sublist存起來以下文解
            # 第一次: 1、2->3->4->5->None
            # 第二次: 2、3->4->5->None
            # 第三次: 3、4->5->None
            # 第四次: 4、5->None
            # 第五次: 5、None
            sublist = copylist.next
            # 把原先的linkedlist指向的物件變為prev(此時也會更動到head.next以及後續對應的next，但不會更動到sublist)
            # 第一次: 1->None
            # 第二次: 2->1->None
            # 第三次: 3->2->1->None
            # 第四次: 4->3->2->1->None
            # 第五次: 5->4->3->2->1->None
            copylist.next = prev
            # 把答案存起來不然等等會沒辦法找回已經過頭的node
            prev = copylist
            # 重新賦值copylist，此時copylist的pointer變為head.next，這樣下一次迴圈處理針對的就是head.next該pointer去定義他的next，最後回傳才能做到一直往下找直到觸發條件
            # 第一次: 2->3->4->5->None
            # 第二次: 3->4->5->None
            # 第三次: 4->5->None
            # 第四次: 5->None
            # 第五次: None
            copylist = sublist 
        # 回傳該值原因是在定義next
        return prev
    
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 如果本身是空值\
            
        if not head or not head.next  :
            return head
        temp = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return temp