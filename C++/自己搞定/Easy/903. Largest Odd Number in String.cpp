#include<iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int right = num.size()-1;
        while(right>=0){
            if(num[right]%2==1){
                return std::string(num.begin(),num.begin()+right+1);
            }
            --right;
        }
        return "";
    }
};