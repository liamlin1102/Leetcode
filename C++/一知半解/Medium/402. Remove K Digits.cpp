#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

//這題偏原理,數字的大小是由最左側（最高位）的數字最先決定的，因此，保持數字序列在最左側盡可能小是至關重要的。
//因此我們要怎麼做 我們要從左到有讓整體數用Montonic stack維持單調
//然後此時會有一個問題 那如果本身數列就是單調呢??
//比方說123456789,那當然就是移除最後面的數字,不可能從開始的地方吧

class Solution {
public:
    string removeKdigits(string num, int k) {
        std::stack<char> montonic;
        std::string answer = "";
        int length = num.size();
        if(num.size()<=k) return "0";
        //從頭到尾看數字
        for (int index=0;index<length;index++){
            //還有k以及montonic有東西,以及目前的數字是比較小的(相同的不用推出去因為只要下一個沒比較大前後推都一樣)
            while(k>0 && !montonic.empty() && montonic.top()>num[index] ){
                montonic.pop();
                k--; 
            }
            //加進去
            montonic.emplace(num[index]);
        }
        //如果還有k代表沒扣完,已經都呈現單調了,那就從尾巴扣回來
        while (k > 0 && !montonic.empty()) {
            montonic.pop();
            k--;
        }

        //把字串倒出來
        while(!montonic.empty()){
            answer += montonic.top();
            montonic.pop();
        }

        //倒過來        
        std::reverse(answer.begin(),answer.end());
        //如果第一個是0並且後面還有其他數字 就把它刪掉 代表那是沒意義的
        while(answer[0]=='0' && answer.size()>1){
            answer.erase(answer.begin());
        }
        
        return answer;
    }
};