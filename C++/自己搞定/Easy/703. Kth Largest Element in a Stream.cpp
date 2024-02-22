#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

class KthLargest {
    std::priority_queue<int> minHeap;
    int kth;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(auto num:nums){
            minHeap.emplace(num*-1);
        }
        while(minHeap.size()>k){
            minHeap.pop();
        }
    }    
    int add(int val) {
        minHeap.emplace(val*-1);
        if(minHeap.size()>kth){
            minHeap.pop();
        }
        return minHeap.top()*-1;
    }
};
