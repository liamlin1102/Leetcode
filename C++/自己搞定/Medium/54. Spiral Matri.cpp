#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int weight = matrix[0].size();
        int rowTopStart =0;
        int columnLeftStart = 0;
        int rowButtomStart = height-1;
        int columnRightStart = weight-1;
        std::vector<int> answer ;
        while(rowTopStart<=rowButtomStart && columnLeftStart<=columnRightStart){
            for(int columnIndex = columnLeftStart;columnIndex<=columnRightStart;columnIndex++){
                answer.emplace_back(matrix[rowTopStart][columnIndex]);
            }
            ++rowTopStart;
            if(rowTopStart>rowButtomStart) break;
            //下
            for(int rowIndex = rowTopStart;rowIndex<=rowButtomStart;rowIndex++){
                answer.emplace_back(matrix[rowIndex][columnRightStart]);
            }
            --columnRightStart;
            if(columnLeftStart>columnRightStart) break;
            //左
            for(int columnIndex = columnRightStart;columnIndex>=columnLeftStart;columnIndex--){
                answer.emplace_back(matrix[rowButtomStart][columnIndex]);
            }
            --rowButtomStart;
            if(rowTopStart>rowButtomStart) break;
            //上
            for(int rowIndex = rowButtomStart;rowIndex>=rowTopStart;rowIndex--){
                answer.emplace_back(matrix[rowIndex][columnLeftStart]);
            }
            ++columnLeftStart;

        }
        return answer;
    }
};