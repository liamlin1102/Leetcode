#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    string largestGoodInteger(string num) {
        int answer = -1;
        for (int index = 0;index<num.size();index++){
            int nextIndex = index+1;
            int count = 1;
            while(nextIndex<num.size() && num[nextIndex]==num[index]){
                ++count;
                ++index;
                ++nextIndex;
            }
            if(count>2) answer = std::max(answer,(int)num[index]-'0');
            count = 0;
        }
        std::string answerStr = to_string(answer);
        return answer ==-1?"":answerStr+answerStr+answerStr;
    }
};