#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxNum=nums[0];
        int answer = 0;
        for (int index=1;index<nums.size();index++){
            if(nums[index]>maxNum){
                answer = nums[index]>=maxNum*2?index:-1;
                maxNum = nums[index];
            }
            else{
                answer = maxNum>= nums[index]*2?answer:-1;
            }
        }
        return answer;
    }
};
