#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

class Solution {
    std::priority_queue<int> pq;
public:
    int findKthLargest(vector<int>& nums, int k) {
        pq = std::priority_queue(nums.begin(),nums.end());
        for (int count=1;count<k;count++){
            pq.pop();
        }
        return pq.top();
    }
};
