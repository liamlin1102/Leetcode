
#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        std::stack<ListNode*> montonicStack;
        ListNode* answer = nullptr;
        while(head){
            while(!montonicStack.empty() && montonicStack.top()->val<head->val){
                montonicStack.pop();
            }
            if(montonicStack.empty()){
                answer = head;
            }
            else{
                montonicStack.top()->next = head;
            }
            montonicStack.emplace(head);
            head = head->next;
        }
        return answer; 
    }
};

