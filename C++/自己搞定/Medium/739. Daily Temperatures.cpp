#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> tempStack;std::vector<int> answer(temperatures.size());int nowIndex=0;
        for(int index = 0;index<temperatures.size();index++){
            nowIndex = index-1;
            while(!tempStack.empty()&&temperatures[index]>tempStack.top()){
                if(answer[nowIndex]==0){
                    answer[nowIndex] = index-nowIndex;
                    tempStack.pop();
                }
                --nowIndex;
            }
            tempStack.emplace(temperatures[index]);
        }
        return answer;      
    }
};