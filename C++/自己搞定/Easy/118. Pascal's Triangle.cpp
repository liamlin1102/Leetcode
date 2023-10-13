#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> temp(1,1);vector<vector<int>> answer;
        answer.emplace_back(temp);
        for(int index = 1;index<numRows;index++){
            vector<int> nowVec(index+1,1);
            vector<int> lastVec = answer[index-1];
            for(int index2=0;index2<lastVec.size()-1;index2++){
                nowVec[index2+1] = lastVec[index2]+lastVec[index2+1];
            }
            answer.emplace_back(nowVec); 
                   
        }
        return answer;      
    }
};