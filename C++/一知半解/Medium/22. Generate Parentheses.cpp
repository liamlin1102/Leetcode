#include<iostream>
#include <bits/stdc++.h>
#include <vector>

//這題就是用backtracking
class Solution {
public:
    void backTracking(int startNum,int endNum,std::string nowString,std::vector<std::string>& answer){
        if(startNum==0 && endNum==0){
            answer.emplace_back(nowString);
            return ;
        }
        if(endNum<startNum){
            return;
        }
        std::string startWord = "(";std::string endWord=")";
        if(startNum!=0){
            nowString+=startWord;
            backTracking(--startNum,endNum,nowString,answer);
            nowString.pop_back();
            ++startNum;
        }
        if(endNum!=0 ){
            nowString+=endWord;
            backTracking(startNum,--endNum,nowString,answer);
        }

    }
    std::vector<std::string> generateParenthesis(int n) {
        int startNum = n;int endNum = n;std::vector<std::string> answer;
        backTracking(startNum,endNum,"",answer);
        return answer;
        
    }
};