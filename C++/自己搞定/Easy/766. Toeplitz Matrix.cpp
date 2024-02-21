#include<iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
    int limitHeight ;
    int limitWidth ;
public:
    bool CheckRule(vector<vector<int>>& matrix,int height,int width){
        int comparingNum = matrix[height][width];
        while(++height<limitHeight && ++width<limitWidth){
            if(comparingNum!=matrix[height][width]) return false;
        }
        return true;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        limitHeight = matrix.size();
        limitWidth = matrix[0].size();
        int lastCheck = 0;
        for (int row=0;row<limitHeight;row++){
            for (int column=0;column<limitWidth;column++){
                if(lastCheck && column>=lastCheck) break;
                if(!CheckRule(matrix,row,column)) {
                    return false;
                }
            }
            ++lastCheck;        
        }
        return true;       
    }
};