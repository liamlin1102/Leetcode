#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        std::string lastWord = "";std::vector<string> answer;
        for(auto word : s){
            if(word!=' '){
                lastWord+=word;
            }
            if(word==' '){
                if(!lastWord.empty()){
                    answer.push_back(lastWord);
                }
                lastWord="";
            }
        }
        if(!lastWord.empty()){
            answer.push_back(lastWord);
        }

        return answer.back().size();
    }
};