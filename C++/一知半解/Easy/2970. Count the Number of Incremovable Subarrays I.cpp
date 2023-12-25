
#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;
//純暴力解，要知道拔掉每個subarray是否為嚴格遞增，我只要檢查拔掉後的array是否遞增就好
class Solution {
public:
    
    int incremovableSubarrayCount(vector<int>& nums) {
        int len = nums.size();int answer = 0;
        //第一個迴圈，為subarray的起點
        for (int startIndex =0 ;startIndex<len;startIndex++){
            //第二個迴圈，為subarray的終點，為了避免重複運算，因此初始值要跟起點一樣往後跑
            for(int endIndex = startIndex;endIndex<len;endIndex++){
                int lastNum = -1 ; 
                bool flag = true;
                //第三個迴圈，把subarray以外的地方都跑過，所以如果loopIndex在start跟end中間就跳過不需檢查
                //若檢查發現上一個值比現在的值還大或是等於，代表指移除目前的範圍不夠，因此不能++，直接break並且不准++
                //如果序列正常，代表移除目前的subarray為正解，方法+1
                for(int loopIndex = 0;loopIndex<len;loopIndex++){
                    if(startIndex<=loopIndex && endIndex>=loopIndex)
                        continue;
                    if(nums[loopIndex]<=lastNum){
                        flag=false;
                        break;
                    }
                    lastNum = nums[loopIndex];
                }
                if(flag) answer++ ; 
            }
        }
        return answer;
    }
};