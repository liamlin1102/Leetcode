#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;
class Solution {
    std::priority_queue<int> pq;
public:
    int lastStoneWeight(vector<int>& stones) {
        this->pq =std::priority_queue(stones.begin(),stones.end());
        while(pq.size()>1){
            int heavist = pq.top();
            pq.pop();
            int secondRock = pq.top();
            pq.pop();
            if(heavist!=secondRock){
                pq.emplace(heavist-secondRock);
            }
        }
        return pq.size()==0?0:pq.top();
    }
};