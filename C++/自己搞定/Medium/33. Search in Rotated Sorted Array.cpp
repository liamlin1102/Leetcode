#include<iostream>
#include <bits/stdc++.h>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int right =nums.size()-1;int left = 0;
        while(right>=left){
            int mid = left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[right]>nums[mid]){
                if(nums[mid]<target && target<=nums[right]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
            else{
                if(nums[mid]>target && target>=nums[left]){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }

            }
        }
        return -1;
    }
};