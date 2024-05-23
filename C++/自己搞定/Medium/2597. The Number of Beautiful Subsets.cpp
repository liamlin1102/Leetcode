#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;


//https://leetcode.com/problems/the-number-of-beautiful-subsets/solutions/5196138/backtracking-k-groups-o-n-m-without-hash-table-3ms-beats-99-79/
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, const int k) {
        const int n = nums.size();
        auto [x_min, x_max]=minmax_element(nums.cbegin(), nums.cend());
        const int M = *x_max - *x_min + 1;
        const int q = (M + k) / k; // ceil((M+1)/k)
        
        // Initialize the frequency array
        char freq[k][q+1];
        memset(freq, 0, sizeof(freq));
        
        for (auto x : nums) {
            auto [i, r] = div(x-*x_min, k);
            freq[r][i]++;
        }
        
        int ans = 1; // Start with 1 fpr the product
        for (int r = 0; r < k; r++) {
            int prev = 1, curr = 1;
            for (int i = 0; i < q; i++) {
                int take = (1 << freq[r][i]) - 1;
                if (i > 0) take *= prev;
                else take *= curr;
                prev = curr;
                curr = curr + take;
            }
            ans *= curr;
        }

        
        return ans-1; //exclude the empty set
    }
};



class Solution {
public:
    int backTracking(std::vector<int>& nums,int k,int startIndex, std::unordered_map<int,int>& numMap){
        int answer = 0;
        for(int start = startIndex;start<nums.size();start++){
            int nowNum = nums[start];
            numMap[nowNum]++;
            if(!numMap[nowNum+k]&&!numMap[nowNum-k]){
                answer += (this->backTracking(nums,k,start+1,numMap)+1);
            }
            numMap[nowNum]--;
        }
        return answer;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        std::unordered_map<int,int> answerMap;
        return this->backTracking(nums,k,0,answerMap);
    }
};