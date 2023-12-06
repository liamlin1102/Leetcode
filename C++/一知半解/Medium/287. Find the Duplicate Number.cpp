#include<iostream>
#include <bits/stdc++.h>
#include <vector>

//這題最難的點，是如何發現nums可以用linklisted的角度
//題目說空間複雜度(1)、不可修改原始nums，導致這題只能用一般的觀測法來處理
//那如何觀測，去想想linkedlisted就是在描述值+下一個的位置
//我們利用，index去對應的找數字，由於題目給的條件最多只會出現(1,count-1)的數字
//因此一個長度5的list，[1,3,2,2,4]就只會出現最大為4，並且最多重複一種數字(不限一個)
//此時我們利用index去maplist[index]的方法搭建出linkedlist
//EX:[1,3,2,2,4]，linkedlist = [nums[0],nums[nums[0]],nums[nums[nums[0]]]....],直觀看起來就是[1(nums[0]),3(nums[1]),2(nums[3]),2(nums[2]),2(nums[2])...]
//就製造出了一個有迴圈的linkedlist
class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        if(nums.size()==2){
            return nums[0];
        }
        int slow = 0;int fast=0;int index=0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        while(nums[index]!=nums[slow]){
            slow = nums[slow];
            index = nums[index];
        }
        return nums[slow];   
    }
};