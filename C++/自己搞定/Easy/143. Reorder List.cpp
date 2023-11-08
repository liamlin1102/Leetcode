#include<iostream>
#include <bits/stdc++.h>
#include <map>
//這題的目的是要[0,n-1,1,n-2...]，這題絲路就是找到中點，中點前的正常，終點後的反轉但由於linkedlist是單向鍊條，
//邏輯就是快慢指針，透過快慢指針找到中點
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* rightNode;
        ListNode* tempLeft;
        ListNode* reverseNode=NULL;
        ListNode* tempRight;
        //當fast以及fast.next 都是空的時要停下來，因為我們需要用到next.next，next是空的會出事        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        //右邊的節點保存起來
        rightNode = slow->next;
        //並且給他null以免拼起來變成無限遞迴
        slow->next = NULL;
        //當右邊還沒走到盡頭
        while(rightNode){
            //反轉跟之前的一個一樣
            //把右邊存起來            
            tempRight = rightNode->next;
            //把現在的右邊放上反轉後的
            rightNode->next = reverseNode;
            //把拚上反轉後的本體重新定義，已讓後面可以繼續拚
            reverseNode = rightNode;
            //把佔存的資料拉出來
            rightNode = tempRight;
        }
        //接下來把他接起來，哪個是空的都停下來因為會是正解
        while(head && reverseNode){
            //把左邊的linkedlisted的next存下來
            tempLeft = head->next; 
            //把反轉過的linkedlisted的next存下來
            tempRight = reverseNode->next; 
            //先放反轉的
            head->next = reverseNode;
            //再放左邊的
            head->next->next = tempLeft;
            //把他重新定義
            reverseNode = tempRight;
            //同上
            head = tempLeft; 
        }     
    }
};