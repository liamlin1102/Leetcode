#include<iostream>
#include <bits/stdc++.h>
#include <map>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
//這題不太難，就是把記憶體本身存在map裡，如果我有新增過新的就用它，沒有就新增，然後一路next 跟 random拚下去
//一開場在map先加入null null ，讓後面遇到的時候加進去，以免new的時候出錯
class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::map<Node*,Node*> nodeMap = {{NULL,NULL}};
        Node* temp = new Node(0);
        Node* answer = temp;
        while(head){
            //如果不在map裡，新增
           if(!nodeMap.contains(head)){
                nodeMap[head] = new Node(head->val);
           }
           //這個是創來下一個放新node
           temp->next = nodeMap[head];
           //移過去等等才能random
           temp = temp->next;
           //如果不包含random 新增
           if(!nodeMap.contains(head->random)){
                nodeMap[head->random] = new Node(head->random->val);
           }
           //給他random
           temp->random = nodeMap[head->random];
           head = head->next; 
        }
        return  answer->next;   
    }
};