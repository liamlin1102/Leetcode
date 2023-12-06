#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;


// 找最長的連續元素，並且重複的不管他，那就一路加到set裡面，然後排序，如果現在加的值跟上個值
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if(nums.size()<=1){
            return nums.size();
        }
        set<int> setNums;
        for(int num : nums){
            setNums.insert(num);
        } 
        int maxLen= 1;int longestLen=1;int preNum = 0;bool first = true;
        for (int num : setNums){
            if (first){
                first = false;
            }
            else{
                if(num-preNum==1){                 
                    maxLen+=1;
                }
                else{
                    longestLen = max(maxLen,longestLen);
                    maxLen = 1;
                }
            }
            preNum = num;           
        }
        return max(maxLen,longestLen);       
    }
};

int main(){
    Solution sol;
    vector<int> test= {0,3,7,2,5,8,4,6,0,1};
    cout<<sol.longestConsecutive(test);

}