#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        std::unordered_map<int,int> allLosers;
        std::vector<int> oneLosers;
        std::set<int>winnerSet;
        for(auto playerVec : matches){
            allLosers[playerVec[1]]++;
        }
        for(auto playerVec : matches){
            if(!allLosers.contains(playerVec[0])) winnerSet.emplace(playerVec[0]);
        }
        for(auto [key,value] : allLosers){
            if(value==1) oneLosers.emplace_back(key);
        }
        sort(oneLosers.begin(),oneLosers.end());
        return std::vector<std::vector<int>>{std::vector(winnerSet.begin(),winnerSet.end()),oneLosers} ;
        
    }
};