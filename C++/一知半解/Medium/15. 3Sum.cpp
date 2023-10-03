#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        //算總和都先排序
        sort(nums.begin(),nums.end());
        //由於題目要求在vector塞入不重複的組合但相加等於0的vector，因此要去想如何不會重複
        //最直觀的方法是，因為排序過了，只要我們迴圈發現現在跟前一個一樣，就跳過以免重複
        //並且left的值默認從現在的index往後，這樣就不會加到重複Case
        for(int index=0;index<nums.size();index++){
            if(index>0 && nums[index]==nums[index-1]){//排序過了，只要我們迴圈發現現在跟前一個一樣，就跳過以免重複
                continue;
            }
            int left=index+1;int right=nums.size()-1;//排序過了，只要left從現在的位置往右數，這樣就不會產生包含之前位置的組合，因為我們的算法會包含所有該數字的case，
            while(right>left){
                int target = nums[index]+nums[left]+nums[right];
                if(target<0){
                    left++;
                }
                else if(target>0){
                    right--;
                }
                else{
                    vector<int> zeroCase{nums[index],nums[left],nums[right]};
                    answer.push_back(zeroCase);
                    while(right>left && nums[left]==nums[left+1]){//一樣為了避免把重複case放進來，發現左邊一樣就可以一直往前走，後面迴圈碰到也會跳過
                        left++;
                    }   
                    while(right>left && nums[right]==nums[right-1]){//一樣為了避免把重複case放進來，發現右邊一樣就可以一直往回走，後面迴圈碰到也會跳過
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return answer ;        
    }
};