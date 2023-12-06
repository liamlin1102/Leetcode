#include<iostream>
#include <bits/stdc++.h>
#include <vector>
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int oneLength = nums1.size();int twoLength = nums2.size();
        int targetIndex = (oneLength+twoLength)/2;//如果不能整除就是這個index，如果可以整除須要targetIndex-1 + targetIndex雙資料
        if(nums1[0]>*(nums2.rbegin())){
            if(targetIndex>=twoLength){
                targetIndex=targetIndex-twoLength;
                return  (oneLength+twoLength)%2!=0?nums1[targetIndex]:(nums1[targetIndex]+nums1[targetIndex-1])/2.0;
            }
            else{
                return  (oneLength+twoLength)%2!=0?nums2[targetIndex]:(nums2[targetIndex]+nums2[targetIndex-1])/2.0;
            }
        }
        if(nums2[0]>*(nums1.rbegin())){
            if(targetIndex>=oneLength){
                targetIndex=targetIndex-oneLength;;
                return  (oneLength+twoLength)%2!=0?nums2[targetIndex]:(nums2[targetIndex]+nums2[targetIndex-1])/2.0;
            }
            else{
                return  (oneLength+twoLength)%2!=0?nums1[targetIndex]:(nums1[targetIndex]+nums1[targetIndex-1])/2.0;
            }
        }
        return 0.0;
    }
    
};