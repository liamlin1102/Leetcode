"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        nhead = Node(0)
        chead = head
        curr = nhead
        dico = {}
        dicn = {}
        count = 0
        while chead:
            curr.next = Node(chead.val,None,None)
            dico[chead] = count
            dicn[count] = curr.next
            curr = curr.next
            chead = chead.next
            count+=1
        cnhead = nhead.next
        while head:
            head_index = head.random
            if head_index:
                index = dico[head_index]        
                cnhead.random = dicn[index]
            cnhead = cnhead.next
            head= head.next
        return nhead.next
