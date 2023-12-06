#include<basetsd.h>
#include<iostream>
#include<map>


class LRUCache {
private:
    struct DoubleListNode
    {
        int key;
        int val;
        DoubleListNode* prev;
        DoubleListNode* next;
        DoubleListNode() :key(0),val(0),prev(nullptr),next(nullptr){}
        DoubleListNode(int key,int val) : key(key),val(val),prev(nullptr), next(nullptr) {}
        DoubleListNode(int key,int val,DoubleListNode* prev) : key(key),val(val),prev(prev), next(nullptr) {}
    };
    std::map<int,DoubleListNode*> mapNode;
    DoubleListNode* start = nullptr;
    DoubleListNode* temp = nullptr;
    DoubleListNode* prev = nullptr;
    int limited = 0;
public:
    LRUCache(int capacity) {
        limited = capacity;
    }
    
    int get(int key) {
        if( !mapNode.contains(key)){
            return -1;
        }
        temp = mapNode[key];
        if(temp!=prev){
            if(temp==start){
                start = start->next;
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            prev->next = temp;
            temp->prev = prev;
            prev = prev->next;
        }
        return  temp->val;
    }
    void put(int key, int value) {
        if(mapNode.contains(key)){
            temp = mapNode[key];
            temp->val = value;
            if(temp!=prev){
                if(temp==start){
                    start = start->next;
                }
                else{
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                prev->next = temp;
                temp->prev = prev;
                prev = prev->next;
            }
        }
        else{
            if(!prev){
                prev = new DoubleListNode(key,value);
                start = prev;
            }
            else{
                prev->next = new DoubleListNode(key,value,prev);
                prev = prev->next;
            }
            if(limited==mapNode.size()){          
                mapNode.erase(start->key);
                start = start->next;           
            }
        }
        mapNode[key] = prev;
    }
};