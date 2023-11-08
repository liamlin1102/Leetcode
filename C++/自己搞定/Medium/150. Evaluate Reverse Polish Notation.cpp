#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;
//奇怪的題目...不解釋

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> answer;int number=0;int number2=0;
        for(std::string word :tokens){
            if(word=="+"){
                number =answer.top();
                answer.pop();
                number2 = answer.top();
                answer.pop();
                answer.emplace(number+number2);
            }
            else if(word=="-"){
                number =answer.top();
                answer.pop();
                number2 = answer.top();
                answer.pop();
                answer.emplace(number2-number);
            }
            else if(word=="/"){
                number =answer.top();
                answer.pop();
                number2 = answer.top();
                answer.pop();
                answer.emplace(number2/number);
            }
            else if(word=="*"){
                number =answer.top();
                answer.pop();
                number2 = answer.top();
                answer.pop();
                answer.emplace(number*number2);

            }
            else{
                answer.emplace(stoi(word));
            }

        }
        return answer.top();      
    }
};