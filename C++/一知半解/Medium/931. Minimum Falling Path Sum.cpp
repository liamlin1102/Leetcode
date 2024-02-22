#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

class Solution {
    std::vector<std::vector<int>> dp ;
public: 
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int length = matrix.size();
        dp = std::vector<std::vector<int>>(length,std::vector<int>(length,0));    
        for (auto i : dp){
            i =  std::vector<int>(0);
        }
        int minNum = INT_MAX;
        for(int row =0;row<length;row++){
            for(int column = 0;column<length;column++){
                if(row==0){
                   
                    dp[row][column] = matrix[row][column];
                }
                else{
                    if(column==0){
                        dp[row][column] = matrix[row][column]+std::min(dp[row-1][column],dp[row-1][column+1]);
                    }
                    else if(column==length-1){
                        dp[row][column] = matrix[row][column]+std::min(dp[row-1][column-1],dp[row-1][column]);
                    }
                    else{
                        dp[row][column] = matrix[row][column]+std::min(dp[row-1][column-1],std::min(dp[row-1][column],dp[row-1][column+1]));
                    }
                }
                if(row ==length-1){
                    minNum = std::min(minNum,dp[row][column]);
                }
            }
        }
        return minNum;
    }
};