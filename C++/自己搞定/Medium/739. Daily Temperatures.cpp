#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;
//要找到哪幾天後的溫度比現在高
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size());
        for (int index = temperatures.size() - 1; index >= 0; --index) {
            int nextIndex = index+1;
            while (nextIndex < temperatures.size() && temperatures[nextIndex] <= temperatures[index]) {
                if (answer[nextIndex] > 0)
                    nextIndex = answer[nextIndex] + nextIndex;
                else 
                    nextIndex = temperatures.size();
            }
            if (nextIndex < temperatures.size()) 
                answer[index] = nextIndex - index;
        }
        return answer;
    }
};


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

