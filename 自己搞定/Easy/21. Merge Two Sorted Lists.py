def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
# 我用了比較縮短時間的方法但有一些太攏長
# 檢查 如果兩個都是空的直接回傳NOme
    if (not list1) and (not list2):
        return 
# 一邊是空的傳另外一個
    elif not list1:
        return list2
    elif not list2:
        return list1
    # 如果1的小於2    
    if list1.val<list2.val:
    # 把1 存下來並且定義新的1.next(影響到temp.next)
        temp = list1
        list1 = list1.next
    else:
    # 反之亦然
        temp = list2 
        list2 = list2.next
    # 把sotre定義成temp以免被重新使用 
    store = temp 
    # 只要有一邊有值
    while  list1 or  list2:
    # 如果list1沒了，那就不用比啦直接接過去就好
        if not list1:
    # 一樣為了避免重新定義temp用store傳下去
            store.next = list2
            return temp  
    # 反之毅然
        elif not list2:
            store.next = list1
            return temp
    # 一樣看誰小，小的就往下接
        if list1.val<list2.val:
            store.next = list1
            list1 = list1.next
        else:
            store.next = list2
            list2 = list2.next
    # 定義store 才能延續
        store = store.next
    return temp


# iteratively
def mergeTwoLists1(self, l1, l2):
    # 直接訂一個虛假的Linked list出來
    dummy = cur = ListNode(0)
    # 當兩個都有值才往下做
    while l1 and l2:
        # 比大小跟上面一樣
        if l1.val < l2.val:
            cur.next = l1
            l1 = l1.next
        else:
            cur.next = l2
            l2 = l2.next
        cur = cur.next
    # 這邊是聰明的寫法，會跳出迴圈代表有一個一定是None 去檢查哪個沒有貼上就好
    cur.next = l1 or l2
    # 由於一開始我們是設定一個假的linkedlist 下面那個才是答案
    return dummy.next
    
# recursively    
def mergeTwoLists2(self, l1, l2):
    # 兩個裡面有一個沒有值的時候檢查
    if not l1 or not l2:
        # 回傳有值的那個
        return l1 or l2
    # 看誰小 誰小就把該物件的next給定義並且把該next帶進去跑
    if l1.val < l2.val:
        l1.next = self.mergeTwoLists(l1.next, l2)
        return l1
    else:
        l2.next = self.mergeTwoLists(l1, l2.next)
        return l2