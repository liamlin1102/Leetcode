#include<iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        std::unordered_map<int,int> countMap ;
        int count = 0;
        for(int num :nums){
            ++countMap[num];
        }
        for(auto kp : countMap){
            int t = kp.second;
            if(t==1)return -1;
            count += t/3;
            if(t%3)count++;
        }
        return count;
    }
};
