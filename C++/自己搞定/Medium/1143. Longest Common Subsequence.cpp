#include<iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    //這題是經典DP題
    //https://mycollegenotebook.medium.com/dynamic-programming-lcs-bef41dcd331d
    //這個文章說明得很清楚
    //為什麼dp長這樣，因為DP找LCS最好的方法是由兩個標籤去尋找
    //我們會做出一個表，他會由上一個階段去製表，
    int longestCommonSubsequence(string text1, string text2) {
        std::vector<std::vector<int>> dp(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));
        for(int index1 = 1;index1<text1.size()+1;index1++){
            for(int index2 = 1;index2<text2.size()+1;index2++){
                if(text1[index1-1]==text2[index2-1]){
                    //由上面那一條的結果去更新，上面那一條的結果是什麼，是前面你有多少字符合LSC(在裡面)
                    dp[index1][index2] =dp[index1-1][index2-1]+1;
                }
                else{
                    dp[index1][index2] = std::max(dp[index1-1][index2],dp[index1][index2-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
}; 