#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int squareStudent= 0;
        int circularStudent= 0;
        int nums = students.size();
        for (int index = 0;index<nums;index++){
            if(students[index]) squareStudent++;
            else circularStudent++;
        }
        for (int index = 0;index<nums;index++){
            if(sandwiches[index]) squareStudent--;
            else circularStudent--;
            if(squareStudent<0) return circularStudent;
            if(circularStudent<0) return squareStudent;            
        }
        return  0;   
    }
};