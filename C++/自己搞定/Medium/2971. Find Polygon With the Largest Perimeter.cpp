#include<iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int sum = 0;int answer = 0;
        for (int num : nums){
            if(sum>num){
                answer = sum+num;
            }
            sum+=num;
        }
        if(answer)return answer;
        else return -1;       
    }
};