#include<iostream>
#include <bits/stdc++.h>
#include <map>
//這題目要刪除掉正確位置的NODE，下面有兩個解法

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//two-pointer

class Solution {
public:
    //由於我們只知道要刪掉的位置在從後面屬過來的n，那我們可以先透過快慢指針，讓快指針先走，製造快慢中間的差距是最後一個，跟要刪掉的前一個
    //那要走多久，由於n是從1開始算，因此我們要先讓fast走n部，如果此時fast會停在最後一個，那slow是會停在要刪掉前一個
    //舉立 1 2 3 4 5 n= 2 ，如果fast先走道3 那這樣fast走到5，slow走到3(正確位置)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next){
            return head->next;
        }
        ListNode* fast = head;  ListNode* slow = head; 
        //n是多少就從0開始往前走幾次
        for(int index=0;index<n;index++){
            fast = fast->next;
        }
        //如果走完是空的，代表我們要扣掉第一個，不能接。
        if(!fast){
            return head->next;
        }
        //把要刪掉前一個跟後一個接起來
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
//vector

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //如果右邊是空的代表我們會刪掉唯一的node，啥都不剩
        if(!head->next){
            return NULL;
        }
        std::vector<ListNode*> vecNode;int length = 0;
        ListNode* answer = head;
        //確定她是不是空的，是的話推進vec
        while(head){
            vecNode.emplace_back(head);
            head= head->next;
            ++length;
        }
        //如果長度跟扣的一樣代表扣掉第一個
        if (length==n){
            return answer->next;
        }
        //把它刪掉
        vecNode[length-n-1]->next= vecNode[length-n-1]->next->next;
        return answer;     
    }
};
