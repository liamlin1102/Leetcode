#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;


//backtracking
class Solution {
public:
    void backTracking(std::vector<int>& nums,int startIndex,std::vector<int> nowNums,std::vector<std::vector<int>>& answer){
        answer.emplace_back(nowNums);
        for(int start = startIndex;start<nums.size();start++){
            nowNums.emplace_back(nums[start]);
            this->backTracking(nums,start+1,nowNums,answer);
            nowNums.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> answer;
        backTracking(nums,0, std::vector<int>(),answer);
        return answer;
    }
};

//bit
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0) {
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }
};

//iterate 
//原理很簡單，每次都把目前所有的result的sub vector加入變數
//比方說{1,2,3},一開始{{}},第一個加入1後加進去{{},{1}},第二個把兩個提出來各自加入2家回去{{},{1},{2},{1,2}},第三次這四個提出來家回去
//{{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}}就是答案

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}}; // Add the empty subset
        for (int num : nums) {
            int size = result.size();
            for (int i = 0; i < size; i++) {
                vector<int> subset = result[i];
                subset.push_back(num);
                result.push_back(subset);
            }
        }
        return result;
    }
};