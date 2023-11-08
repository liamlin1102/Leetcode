#include<iostream>
#include <bits/stdc++.h>
#include <vector>
//這題被大神解惑了，下面的寫法很酷，有幾個關鍵點
class Solution {
public:
//這題是使用左閉右閉的方式，正常來說左閉右閉下面要用>=以免有地方沒被查到，並且裡面要補right=mid-1。但這題都沒有，是怎麼做到的
    int findMin(std::vector<int>& nums) {
        int left=0,right = nums.size()-1;
        if(nums[right]>nums[left]){
            return nums[left];
        }
        if(nums.size()==1){
            return nums[0];
        }
        while(right>left){
            int mid = left+(right-left)/2;
            //關鍵就在這裡，他的關鍵就是這裡，因為我們比較的target是 最右邊的值，因此就算我們真得進去right = mid ，下次mid也會跟隨調整
            //因此等到彈出的那一刻，left == right ，此時就會是答案
            if(nums[mid]>nums[right]){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return nums[left];    
    }
};
//下面是剛正樸實的解法，左閉右開，下面用大於
class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int left=0,right = nums.size(),firstNum=nums[0];
        if(nums[right-1]>nums[left]){
            return nums[left];
        }
        if(nums.size()==1){
            return nums[0];
        }
        while(right>left){
            int mid = left+(right-left)/2;
            if(nums[mid]>=firstNum){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return nums[left];    
    }
};