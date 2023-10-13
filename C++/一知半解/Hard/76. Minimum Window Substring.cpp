#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

//這題一開始思路還算齊全，但有兩個問題我沒處理到
//首先如果要找最小的substing，會有幾種可能
//1. 假設 t = "abc",最小字串有可能是"BEDSWCORXA"，這是跑map後完全沒問題，不論長度跟值都是正確的
//第二種可能是 "BEDSBSCORWA"，這是map跑完後長度沒問題(因為最後才碰到A)，但值是有問題的，我們都加了一次B要修正
//第三種可能是 t="aa",最小字串 "aa"，此時，在第一個a的時候長度沒問題，但值是有問題，要等第二次
//會發現如果我們等到結果跑出來，不論用map的值或是長度都會有衝突，這就是卡住的第一個點
//因此要轉向思考，我們應該每次在iterate 字串的時候檢查該字串map的值跟t map的值是否相同，相同代表此時這個數字合格了
//即便他往右變多了還是合格，而等到合格數量=t map的長度，代表目前的字串就是合格的字串
//此時結束了嗎，沒有，因為左邊還沒確定是否合格，我們進來該條件後，統計字串長度跟目前的左邊當開始點記下來(這樣就不用維護字串)
//然後把左邊逐一往右減，並且每次減之前檢查減的值是否在 tmap裡面，如果是在檢查減之前該值t map 跟字串map是否相等
//如果相等代表什麼，代表我這一減下去，此時就不合格了，那我就把紀錄合格的次數-1，就好
//這邊有延伸問題，那中間的是否會有不正確字串產生，當然會
//比方說條件一，"BEDSWCORXA"，我們減掉B的那一刻就會變成不是最短字串，那這樣此時left會在E上，此時我們下一個字母假設是B
//變成EDSWCORXAB，那這樣會進入迴圈，此時的確不是最短，但我們會逐步修正，把left慢慢往右移動到C會記錄正確的長度
//然後到了left 到了O跳出迴圈，繼續找一下個

//第二個問題，我使用了文字維護，這樣速度會慢非常多，應該要把right-left+1 存起來，代表最小字串的長度，然後把目前的left當作一個起始index存起來
//等解答的時候只要去確認 我們的最小字串的長度是不是INT_MAX，如果是代表根本沒有發生過合規字串，如果不是INT_MAX，
//那就從 起始index 往後取substring，長度就是我們存好的

class Solution{
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()){
            return"";//當t比s長，存個毛，一定不合規
        }
        int left =0;std::unordered_map<char,int> checkMap,tempMap;int miniStart =0 ;int sliceLen=INT_MAX;int corrcetTimes = 0; 
        //做檢查用的map
        for(char word : t){
            checkMap[word]+=1;
        }
        for(int right = 0;right<s.size();right++){
            char rightWord = s[right];
            //如果是符合條件的字，則把長度++，順便撿查value是否相同，相同代表這字串這個字是合規的
            if(checkMap.contains(rightWord)){
                if(++tempMap[rightWord]==checkMap[rightWord]){
                    ++corrcetTimes;
                }
                //當合規長度==checkMap長度，代表合格的次數跟出現的字母相同，因為值要一樣因此兩個a之類的也會被加進同一次合規次數
                while(corrcetTimes==checkMap.size()){
                    char leftWord= s[left];
                    //如果存的長度比較小，把現在的left當開始點存下來，並把長度也存下來，先更新，因為會進來就是合規，記完在減
                    if(sliceLen>(right-left+1)){
                        miniStart = left;
                        sliceLen = right-left+1;
                    }
                    //如果目前的字是檢查字，在減之前要先觀測在檢查map value是否相同，相同的話代表，減掉會開始異常，把合規次數減掉
                    if(checkMap.contains(leftWord)){
                        if(tempMap[leftWord]-- == checkMap[leftWord]){
                           --corrcetTimes; 
                        }
                    }
                    //每次做完都要往左
                    left++;
                }
            }
        }
        return sliceLen==INT_MAX?"":s.substr(miniStart,sliceLen);
    }
    string minWindow_bad(string s, string t) {
        if(t.size()>s.size()){
            return"";
        }
        if(t.size()==1&&s.size()==1){
            
            if(t[0]==s[0]){
                return  {t[0]};
            }
            else{
                return"";
            }
        }
        int left =0;int right=0;std::unordered_map<char,int> checkMap;std::unordered_map<char,int> tempMap;
        std::string answer="";std::string tempString="";int correctCounts = 0;
        for(char word : t){
            ++checkMap[word];
        }
        while(right <s.size()){
            char rightWord = s[right];char leftWord = s[left];
            tempString+=rightWord;
            if(checkMap.contains(rightWord)){
                if(++tempMap[rightWord]==checkMap[rightWord]){
                    ++correctCounts;
                };              
            }  
            while(correctCounts==checkMap.size()){
                leftWord = s[left];
                if(answer=="")
                {
                    answer =tempString; 
                }            
                answer = tempString.size()<answer.size()?tempString:answer;     
                if(checkMap.contains(leftWord)){
                    if(tempMap[leftWord]-- == checkMap[leftWord])
                    {
                        --correctCounts;
                    }
                }
                tempString.erase(0,1);
                ++left; 
            }
            ++right;
        } 
        return answer;  
    }
};