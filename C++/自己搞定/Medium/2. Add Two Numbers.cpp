#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;


//這題就是把Linkedlisted當數字，他還幫你reverse過，真貼心
//相加後若第一或第二或是有進位，都要繼續
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode();ListNode* cur = answer;int target = 0;int carry = 0;
        while(l1 || l2 || carry){
            target = carry;//聰明寫法
            if(l1){
                target += l1->val;
                l1 = l1->next;
            }
            if(l2){
                target += l2->val;
                l2 = l2->next;
            }  
            carry = target/10;//聰明寫法
            target = target>9?target-10:target;
            cur->next = new ListNode(target);
            cur = cur->next;
        }
        return answer->next;
    }
};