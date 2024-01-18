#include<iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int length = cost.size();
        int costDp[length];
        costDp[0] = cost[0];
        costDp[1] = cost[1];
        for (int index =2;index<length;index++){
            costDp[index] = cost[index] + std::min(costDp[index-1],costDp[index-2]);
        }
        return std::min(costDp[length-1],costDp[length-2]);
    }
};