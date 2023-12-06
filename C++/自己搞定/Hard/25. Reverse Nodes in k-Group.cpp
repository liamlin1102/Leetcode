#include<basetsd.h>
#include<iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    bool moveNode(ListNode* &fast,int k){
        for(int index =0; index<k;++index){
            if(!fast)return false;
            fast = fast->next;
        }
        return true;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
         ListNode* slow =dummyHead;
         ListNode* fast = head;
         ListNode* next=nullptr;
         ListNode* temp=nullptr;
         ListNode* prev =nullptr;
         ListNode* tempNext = nullptr; 

         while (fast){
            if(!moveNode(fast,k))return dummyHead->next;
            next = slow->next;
            tempNext = next;
            while(next!=fast){ 
                temp=next->next;
                next->next = prev;
                prev = next;
                next = temp;
            }
            slow->next = prev;
            tempNext->next = fast;
            slow = tempNext;
         }
         return  dummyHead->next;      
    }
};