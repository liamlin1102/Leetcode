#include<iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int left =0;
        int right = s.size()-1;
        int leftCount = 0;
        int rightCount=0;
        std::unordered_set<char> wordSet{'a','e','i','o','u','A','E','I','O','U'};
        while(left<=right){
            if(wordSet.contains(s[left]))
                ++leftCount;
            if(wordSet.contains(s[right]))
                ++rightCount;
            ++left;
            --right;
        }
        return leftCount==rightCount;      
    }
};