#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;
class Solution {
    std::priority_queue<std::pair<int,std::vector<int>>> pq;
public:
    vector<vector<int>> kClosest(vector<vector<int>> points, int k) {
        vector<vector<int>> answer;
        for(auto nums:points){     
            pq.emplace((pow(nums[0],2)+pow(nums[1],2))*-1,nums);
        }
        while(answer.size()<k){
            answer.emplace_back(pq.top().second);
            pq.pop();
        }   
        return answer;
    }
};