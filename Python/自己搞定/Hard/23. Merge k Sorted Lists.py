class Solution:
    # 第一種暴力解O(N*(node數量))
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        # 給一個list把所有東西展開放進去
        arr = []
        # 如果裡面有東西就繼續
        for l in lists:
            # 當它變成None停止
            while l:
                # 一直加 然後下一個
                arr.append(l.val)
                l = l.next
        # 排序他們
        arr.sort()
        res = ListNode(0)
        rNext = res
        # 照順序加入Linked，list
        for d in arr:
            rNext.next = ListNode(d)
            rNext = rNext.next
        return res.next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists or len(lists)==0: return None
        while len(lists)!=1:
            merged_lists = []
            for r in range(0,len(lists),2):
                l1 = lists[r]
                l2 = lists[r+1] if r+1<len(lists) else None
                l3 = self.merge_two_lists(l1,l2)
                merged_lists.append(l3)
            lists = merged_lists
        
        return lists[0]
    
    def merge_two_lists(self,l1,l2):
        dummy = prev = ListNode()
        while l1 and l2:
            if l1.val < l2.val:
                prev.next = l1
                prev = l1
                l1 = l1.next
            else:
                prev.next = l2
                prev = l2
                l2 = l2.next
        if l1 or l2:
            prev.next = l1 if l1 else l2
        
        return dummy.next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists or len(lists)==0: return None
        while len(lists)!=1:
            merged_lists = []
            for r in range(0,len(lists),2):
                l1 = lists[r]
                l2 = lists[r+1] if r+1<len(lists) else None
                l3 = self.merge_two_lists(l1,l2)
                merged_lists.append(l3)
            lists = merged_lists
        
        return lists[0]
    
    def merge_two_lists(self,l1,l2):
        dummy = prev = ListNode()
        while l1 and l2:
            if l1.val < l2.val:
                prev.next = l1
                prev = l1
                l1 = l1.next
            else:
                prev.next = l2
                prev = l2
                l2 = l2.next
        if l1 or l2:
            prev.next = l1 if l1 else l2
        
        return dummy.next
    
class Solution:
    def mergeKLists(self, lists):
        from heapq import heappush, heappop, heapreplace, heapify
        dummy = node = ListNode(0)
        h = [(n.val, n) for n in lists if n]
        heapify(h)
        while h:
            v, n = h[0]
            if n.next is None:
                heappop(h) #only change heap size when necessary
            else:
                heapreplace(h, (n.next.val, n.next))
            node.next = n
            node = node.next

        return dummy.next
import heapq
class Solution:
    def mergeKLists(self, lists):
        h = []
        for i in lists:
            if i:
                heapq.heappush(h,(i.val, i))
        res = cur = ListNode(0)
        while h:
            v,node = heapq.heappop(h)
            print(v)
            cur.next = node
            cur = cur.next
            if node.next :
                heapq.heappush(h,(node.next.val,node.next))
        return res.next
    
    
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return

        heap = []
        cur = ListNode()
        dummy = cur

        for node in lists:
            while node:
                heapq.heappush(heap, node.val)
                node = node.next
        
        while heap:
            cur.next = ListNode(heapq.heappop(heap))
            cur = cur.next
        
        return dummy.next
    
class Solution(object):
    def mergeKLists(self, lists):
        if not lists:
            return None
        if len(lists) == 1:
            return lists[0]
        mid = len(lists) // 2
        l, r = self.mergeKLists(lists[:mid]), self.mergeKLists(lists[mid:])
        return self.merge(l, r)
    
    def merge(self, l, r):
        dummy = p = ListNode()
        while l and r:
            if l.val < r.val:
                p.next = l
                l = l.next
            else:
                p.next = r
                r = r.next
            p = p.next
        p.next = l or r
        return dummy.next
    
    def merge1(self, l, r):
        if not l or not r:
            return l or r
        if l.val< r.val:
            l.next = self.merge(l.next, r)
            return l
        r.next = self.merge(l, r.next)
        return r

























# 寫超爛直接無視
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return 
        start = True
        head = ListNode()
        cur = head
        while start :
            dic = {}
            for index,node in enumerate(lists):
                if not node:
                    continue
                if not dic:
                    min_num = node.val
                    dic[node.val] = index
                else:
                    if node.val<min_num:
                        min_num = node.val
                        dic[node.val] = index
            if not dic:
                start = False
                break
            cur.next = lists[dic[min_num]]
            cur = cur.next
            lists[dic[min_num]] = lists[dic[min_num]].next
        return head.next