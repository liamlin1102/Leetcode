#include<iostream>
#include <bits/stdc++.h>
#include <vector>
//最長的字串開頭，雖然跑出來不快，但應該是最優解O(N)
//把整個字串先排序，第一個就會是最短的，最後一個是最長的
//用最短的去看因為最長的相同字串開頭，最長就是整個最短
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::sort(strs.begin(),strs.end());
        std::string answer = "";
        std::string minStr = strs[0];
        std::string maxStr = *strs.rbegin();
        for(int index =0;index<strs[0].size();index++){
            if(minStr[index]!=maxStr[index]){
               break; 
            }
                answer+=minStr[index];
        }
        return answer;
    }
};