#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;
//這題就是用兩個map或是vector存，檢查有沒有s1的排列組合內容，只要維護好那個字串長度內的內容，如果不一樣，則加右邊減左邊
//並且每次更改就檢查兩者是否相等，相等的話就跳true，一直到回圈結束就是fakse

class Solution {
//上面的方法比較快，因為int count1[26]={0}，速度會比vector比較快
//而且不用map直接用ascii code把出現的字母-'a'，再加入對應的int[index]來檢查
private:
    bool checkEqual(int a[26], int b[26])
    {
        for(int i =0; i<26; i++)
        {
            if(a[i] != b[i])
                return 0;
            
        }
        return 1;
    }
 public:
    bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};
        for(int i = 0; i<s1.length(); i++){
            int index = s1[i] - 'a';
            count1[index]++;
        }

        int i = 0;
        int windowSize = s1.length();
        int count2[26] = {0};

        while(i<windowSize && i<s2.length()){
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        if(checkEqual(count1, count2)){
            return 1;
        }

        while(i<s2.length()){
            char newChar = s2[i];
            int index = newChar - 'a';
            count2[index]++;

            char oldChar = s2[i-windowSize];
            index = oldChar - 'a';
            count2[index]--;
            i++;

            if(checkEqual(count1, count2)){
                return 1;
            }


        }
        return 0;

    }
    bool checkEqual(std::vector<int> vec,std::vector<int> vec2){
        for(int index=0;index<26;index++){
            if(vec[index]!=vec2[index]){
                return false;
            }
        }
        return true;
    }
    //慢
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
};