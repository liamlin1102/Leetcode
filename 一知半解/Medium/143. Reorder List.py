# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# 解題核心，找中間點，然後翻轉後半段，要記得linked list的關鍵，一定要從前一個往後找，因此用反轉後面的方式後一前一後來拚出答案，由於題目要求要原地址回傳，操作要注意，
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
    # 用快慢指針的方式找中間值，由於linkedlist的特點就是無法跳，因此一個走2一個走1，走2的走到底，走1的剛好會走到中間
        fast = head
        slow = head
        # 複製一個來更改head 
        cur = head
        # 複製一個來拼接
        copyhead = head.next
        # 當fast本身不是空的或是next不是空
        while  fast and  fast.next:
            # 走2
            fast = fast.next.next
            # 走1
            slow = slow.next
        # 跳出代表走2到底了(next到底)
        # 反轉後面，這裡是超級關鍵，極度考驗Linkedlist的觀念，假設 head = [1,2,3,4,5] 、slow 就會是 [3,4,5]
        # 如果我們翻轉了3TO4TO5 變成 5 TO 4 TO 3 原始的head也會受到影響，因為原始的3的pointer是TO 4的 pointer 
        # 然而現在反轉了，3的pointer的next被重新定義成None，4的被重新定義成3,5的重新被定義成4
        # 此時head會變成1 TO 2 TO 3 TO None
        # slow 變成 5 TO 4 TO 3 TO None
        slow = self.reverselist(slow)
        # 當然copyhead 也會被影響成 2 TO 3 TO None
        # 會了避免變成無限recycle的Linkedlist，我們在拼接前要檢查slow跟copyhead是否相等，並且檢查copyhead是不是空的
        # 由於slow適從中間值開始算，肯定比copyhead長，至多也一樣長
        while copyhead and not slow is copyhead  :
            # 把copyhead的next存起來
            temp_copyhead = copyhead.next
            # 把slow的next存起來
            temp_slow = slow.next
            # 把cur的next更改為slow 此時會變成1 TO 5 TO 4 TO 3 TO None
            # 第二次: 1 TO 5 TO 2 TO 4 TO 3 TO None
            cur.next = slow
            # 把 cur 的next.next變成copyhead ，此時會變成 1 TO 5 TO 2 TO 3 TO None
            # 第二式: 1 TO 5 TO 2 TO 4 TO 3 TO None
            cur.next.next = copyhead
            # 把cur定義成next.next才能往下
            cur = cur.next.next
            # 一樣往下兩個存的值
            copyhead = temp_copyhead
            slow = temp_slow
    
    def reverselist(self,head):
        cur = head
        prev = None
        while cur:
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp
        return prev
# 比較好的寫法
def reorderList(self, head):
    if not head:
        return
        
    # 一樣
    slow = fast = head 
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    # 反轉優良寫法
    pre, node = None, slow
    # 只要還有node代表還沒轉完
    while node:
        # 把pre定義成node(原始)，node.next定義成pre(原始)，node定義成node.next(原始)
        # 這邊活用了python的語言特性，他會同時幫你把右邊的變數賦值給左邊，並且會獨立不互相干擾跟先後問題
        pre, node.next, node = node, pre, node.next
    
    # first就是前半段
    # pre就是後半段
    first, second = head, pre
    # 如果second.next有東西，由於second是反轉並且最後執行，只要second.next是None 此時的head一定會呈現[......,second.val,None]，因為我們把
    while second.next:
        # 由於這邊也活用了python的能力，我們把firest的next變成，後半段第一個，並且再把first的頭變first
        # 演示一下，假設first = 1 TO 2 TO 3 TO None 、seconde = 4 TO 3 TO None
        #  first.next = second，first 變成 1 TO 4 TO 3 TO None，head = 1 To 4 TO 3 TO None
        # first = first.next，first 變成  2 TO 3 TO None ， head 不變化
        first.next, first = second, first.next
        #  second.next = first，second 變成 second = 4 TO 2 TO 3 TO None ,head = 1 TO 4 TO 2 To 3  TO None
        # second = second.next，second 變成 seconde = 3 TO None
        second.next, second = first, second.next
        # 跟鬼一樣，活用地址的概念 只要把正確的pointer指向正確的pointer head 就會自己改變
    return 