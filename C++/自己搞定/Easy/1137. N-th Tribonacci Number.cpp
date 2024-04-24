
#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        std::vector<int> dp(n+1,0);
        dp[0]=0;
        for (int index=1;index<n+1;index++){
            if(index<3){
                dp[index]=1;
            }
            else{
                dp[index] = dp[index-1]+dp[index-2]+dp[index-3];
            }

        }
        return dp[n];
    }
};