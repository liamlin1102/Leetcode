#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        for(auto str : t){
            if(s[0]==str){
                s.erase(0,1);
            }
        }
        return s.empty();        
    }

    bool isSubsequence(string s, string t) {
        int count = 0;
        for(char word : t){
            if(s[count]==word){
                ++count;
            }
        }
        return count==s.size();
    }
};