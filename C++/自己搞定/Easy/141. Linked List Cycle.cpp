#include<iostream>
#include <bits/stdc++.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head||!head->next){
            return 0;
        }
        ListNode* fast = head;ListNode* slow =head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                return 1;
            }
        }
        return 0;
        
    }
};