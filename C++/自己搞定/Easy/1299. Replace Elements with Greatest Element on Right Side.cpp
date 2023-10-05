#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> answer(arr.size(),-1);int right=arr.size()-2;int maxNum = arr[arr.size()-1];
        while(right>=0){
            answer[right] = maxNum;
            maxNum = max(maxNum,arr[right]);
            right--;
        }
        return answer;

        
    }
};