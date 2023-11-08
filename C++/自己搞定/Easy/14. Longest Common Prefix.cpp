#include<iostream>
#include <bits/stdc++.h>
#include <vector>
//最長的字串開頭，
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string prefix = strs[0];
        for(std::string target : strs){
            int stopLen  = std::min(prefix.size(),target.size());
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