#include<iostream>
#include <bits/stdc++.h>
#include <vector>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();int columns =  matrix[0].size();int allSize = rows*columns;
        if(rows==1&&columns==1){
            return target==matrix[0][0];
        }
        int left = 0; int right = allSize;int row=0;int column=0;
        while(right>left){
            int mid = left+(right-left)/2;
            row = (mid)/columns;
            column = (mid)%columns;
            if(matrix[row][column]==target){
                return true;
            }
            else if(matrix[row][column]>target){
                right = mid;
            }
            else if(matrix[row][column]<target){
                left = mid+1;
            }
        }
        return false;
        
    }
};