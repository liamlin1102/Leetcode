#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int,int> mapArr;
        std::unordered_set<int> setArr;
        for(auto num : arr){
            mapArr[num] +=1 ;
        }
        for(auto pair :mapArr){
            if(setArr.count(pair.second)) return false;
            setArr.insert(pair.second);
        }
        return true;
    }
};
