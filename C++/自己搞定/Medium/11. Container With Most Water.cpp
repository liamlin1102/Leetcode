#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;int right = height.size()-1;int answer = 0;
        while(right>left){
            answer = max(min(height[right],height[left])*(right-left),answer);
            if(height[right]>height[left]){
                left++;
            }
            else{
                right--;
            }
        }
        return answer;
    }
};