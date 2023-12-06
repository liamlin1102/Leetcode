#include<iostream>
#include <bits/stdc++.h>
#include <map>
//這題目就標準的linked list題目

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = new ListNode(0);
        ListNode* answer = temp;
        while(list1 && list2){
            if(list1->val>list2->val){
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
            else{
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
        }
        while(list1){
            temp->next = list1;
            temp = temp->next;
            list1 = list1->next;            
        }
        while(list2){
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;          
        }
        return answer->next;     
    }
};