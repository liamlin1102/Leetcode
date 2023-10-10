#include<iostream>
#include <bits/stdc++.h>
#include <map>

//這題就是用兩個map或是vector存，檢查有沒有s1的排列組合內容，只要維護好那個字串長度內的內容，如果不一樣，則加右邊減左邊
//並且每次更改就檢查兩者是否相等，相等的話就跳true，一直到回圈結束就是fakse

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        std::unordered_map<char,int> permutationMap;std::unordered_map<char,int> answer;int left = 0;int permutationLen = 0;
        for(char str : s1){
            if(!permutationMap.contains(str)){
                permutationMap[str]=0;
            }
            permutationMap[str]+=1;
            permutationLen++;
        }
        for(int right =0;right<s2.size();right++){
            if(!answer.contains(s2[right])){
                answer[s2[right]]=0;
            }
            answer[s2[right]]+=1;

            if(right-left+1==permutationLen){
                if(answer==permutationMap){
                    return true;
                }
                answer[s2[left]]-=1;
                if(answer[s2[left]]==0){
                    answer.erase(s2[left]);
                }
                left++;         
            }
        }
        return false;
    }

    //方法2
    bool checkEqual(std::vector<int> vec,std::vector<int> vec2){
        for(int index=0;index<26;index++){
            if(vec[index]!=vec2[index]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(std::string s1, std::string s2) {
        std::vector<int> permutationVector(26); ;std::vector<int> answer(26);int left = 0;int permutationLen = 0;
        for(char str : s1){
            ++permutationVector[str-'a'];
            ++permutationLen;
        } 
        for(int right=0;right<s2.size();right++)
        {            
            ++answer[s2[right]-'a'];
            if(right-left+1>permutationLen){
                --answer[s2[left]-'a'];
                ++left;
            }
            if(checkEqual(permutationVector,answer)){
                return true;
            }

        }
        return false;
    }
};