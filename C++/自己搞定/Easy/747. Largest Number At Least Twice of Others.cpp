#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;
//找最大是不是第二大的兩倍
//只要每次去計算當前的值是否是最大值的兩倍
//如果當前甚至比最大還大連帶更新最大值
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
