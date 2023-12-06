#include<iostream>
#include <bits/stdc++.h>
#include <vector>


struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int val):val(val),next(nullptr){}
    ListNode(int val,ListNode* next):val(val),next(next){}

};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::priority_queue<int,std::vector<int>,std::greater<int>> minHeap ;
        ListNode* dummyNode = new ListNode();
        for(ListNode* listNode : lists){
            while(listNode){
                minHeap.emplace(listNode->val);
                listNode = listNode->next;
            }
        }
        while(!minHeap.empty()){
            int node = minHeap.top();
            dummyNode->next = new ListNode(node);
            dummyNode = dummyNode->next;
            minHeap.pop();
        }
        return dummyNode->next;
        
    }
};