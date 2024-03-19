#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int length = nums.size();
        int oriSum = (length*(length+1))/2;
        int nowSum = 0;
        int dupNum = -1;
        for(int index=0;index<nums.size();index++){
            int realIndex = abs(nums[index])-1;
            if(nums[realIndex]<0) dupNum=abs(nums[index]);
            nowSum += abs(nums[index]);
            nums[realIndex] = nums[realIndex]*-1;
        }   
        return std::vector<int>{dupNum, dupNum + oriSum-nowSum};
    }
};