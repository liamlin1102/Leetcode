#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

//很簡單，如何找到最大的同時有正有負，我一開始的想法就是一個正的、一個負的
//根據題目給的範圍 設定index長度總長,根據上下去比對是否有另一個彼此存在 如果有舊更新最大值

//另一個方法是什麼，更直觀但比較慢，我直接排序後用two pointer，只要找到的第一個左右相等 那必然是最大的
//如果沒相等呢 那就看右邊比較大還是左邊abs後比較大,如果左邊abs比較大 代表左邊要往右靠 右邊已經不可能有他的對稱值反之亦然

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int pos[1000] = {0};
        int neg[1000] = {0};
        int answer = -1;
        for (int num : nums){
            if(num>0){
                int index = num-1;
                pos[index]++;
                if(neg[index]) answer = std::max(answer,num);
            }
            else{
                int index = std::abs(num)-1;               
                neg[index]++;
                if(pos[index]) answer = std::max(answer,index+1);
            }
        }
        return answer;
    }
};

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int left = 0; int right = nums.size()-1;
        while(right>left){
            int leftNum = nums[left]*-1;
            int rightNum = nums[right];
            if(leftNum==rightNum) return  rightNum;
            if(leftNum<rightNum) right--;
            else left++;
        }
        return -1;
    }
};
