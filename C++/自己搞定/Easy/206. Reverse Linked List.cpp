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

//recrusive的方法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {           
        return reverse(head,NULL);
    }
    //由於要轉整個node，你如果到最後一個才那麼做會失敗，因此中間就要先操作尾部在recrusive
    ListNode* reverse(ListNode* curr,ListNode* prev) {
        //中斷條件
        if(!curr){
            return prev; 
        }
        //next存
        ListNode* next = curr->next;
        //curr->next放上一個
        curr->next =  prev; 
        //上一個變成現在的值 
        prev = curr;  
        return reverse(next,prev);
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        ListNode* answer= new ListNode();
        //基本上一樣
        while(head){
            //把next 存起來
            temp = head->next;
            //head下一個變成answer下一個
            head->next = answer->next;
            //answer下一個變成head(重置讓他後面接的位置正確)
            answer->next = head;
            //還原
            head = temp;
        }
        return answer->next;
    }
};