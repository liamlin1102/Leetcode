#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    char ToLower(char word){
        if(word>='A'&& word<='Z'){
            word =word -'A'+'a';
            }
        return word;
    }
    bool checkWord(char word){
        return (word>='a' && word<='z')||(word-'0'>=0 && word-'0'<=9);
    }
    bool isPalindrome(string s) {
        if(s.size()<=1){
            return true;
        }
        int left =0; int right = s.size()-1;bool answer = false;
        while (right>left){
            char leftWord= ToLower(s[left]);
            char rightWord= ToLower(s[right]);    
            if(!checkWord(rightWord)){
                right--;
            }
            else if(!checkWord(leftWord)){
                left++;
            }
            else{         
                if (leftWord!=rightWord){
                    return false;
                }
                else{
                    left++;
                    right--;
                }
            }
        }
        return true;
    }
};