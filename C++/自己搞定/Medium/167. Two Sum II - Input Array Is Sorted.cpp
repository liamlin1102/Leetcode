#include<iostream>
#include <bits/stdc++.h>


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0;int right = numbers.size()-1;std::vector<int> answer;
        if (numbers.size()==2){
            answer = {1,2};
            return answer;
        }
        while(right>left){
            if (numbers[right]+numbers[left]>target){
                right--;
            }

            else if (numbers[right]+numbers[left]<target){
                left++;
            }
            else{
                answer.push_back(left+1);
                answer.push_back(right+1);
                break;
            }

        }
        return answer;
    }
};
