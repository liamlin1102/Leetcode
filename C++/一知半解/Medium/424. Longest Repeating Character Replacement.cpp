#include<iostream>
#include <bits/stdc++.h>
#include <map>

using namespace std;
//這題思路就是，既然有轉換次數的概念，我們需要找到在字串長度內-出現最多次的字符是否有大於轉換次數，沒有的話就沒問題繼續走
//比方說"AAAAABBBBCBB" k=4，此時C的時候有10個字、A有5個但只可轉換4次，此時就代表違規，我們要從後面扣回來並讓left長度加一，此時不論扣掉什麼字符都無所謂
//因為我們的目的是找出，最長的字串，只要字串長度內-出現最多次的字符都大於轉換次數，代表該字串是違規字串，left會一直跟著動，這樣得到答案的長度
//會不變，依然符合題意，當我發現最多字串的字足夠多到會讓轉換次數有剩下(或剛好為0)，就不走left讓右邊變長

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> setCounts;int left=0;int right = 0;int answer=0;int maxFreq=0;
        if(s.size()==1){
            return 1;
        }
        if(s.size()-k<=1){
            return s.size();
        }

        //無條件往右走，加入現在的點的字符
        for(right=0;right<s.size();right++){
            if(!setCounts.contains(s[right])){
                setCounts[s[right]]=0;
            }
            setCounts[s[right]]+=1;
            //確定slice裡面的字串最多字符出現的次數
            maxFreq = max(maxFreq,setCounts[s[right]]);
            //如果我發現總長-最多>轉換次數，代表
            if(right-left+1-maxFreq>k){
                setCounts[s[left]]-=1;
                left++;
            }
            answer = max(answer,right-left+1);
        }
        return answer;        
    }
    
};