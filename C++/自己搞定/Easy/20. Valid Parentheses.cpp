#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;
//這題運用了stack的特性，他會一直從右邊近來，因此只要左邊的符號近來，就只要等右邊的符號近來然後把它消掉
//就像消消樂，反正只要符合規定，遲早會被消除
//ex: s="{}()[][{}][]"，stack變成 {}，發現一對削掉，然後到第三個後{發現沒另一半繼續推，[{}消掉第一個，同時輸出第二個]，這樣就消完了，裡面是空的
class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0){
            return false;
        }
        std::stack<char> stack;
        std::unordered_map<char,char> checkRule{
            {'}','{'},
            {')','('},
            {']','['}
        };
        for(char word : s){
            if(!stack.empty()&&stack.top()==checkRule[word]){
                stack.pop();
            }
            else{
                stack.emplace(word);
            }
        }
        return stack.empty();       
    }
};