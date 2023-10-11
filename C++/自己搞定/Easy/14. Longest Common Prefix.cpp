#include<iostream>
#include <bits/stdc++.h>
#include <vector>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string prefix = strs[0];
        for(string target : strs){
            int stopLen  = min(prefix.size(),target.size());
            prefix = prefix.substr(0,stopLen);
            for(int index=0;index<stopLen;index++){
                if(target[index]!=prefix[index]){
                    prefix = prefix.substr(0,index);
                    break;
                }
            }
        }
        return prefix;
    }
};