#include<iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        std::string answer = "";
        for(char word : s){
            answer+=std::to_string(word-'a'+1);
        }

        while(k>0){
            int thisNum = 0;
            for (char word : answer){
                thisNum+=(word-'0');
            }
            answer = std::to_string(thisNum);
            k--;
        }
        return std::stoi(answer);        
    }
};

class Solution {
public:
    int sumDigits(int num) {
        int sum = 0;
        while(num) {
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    
    int getLucky(string s, int k) {
        int sum = 0 ; 
        for(auto it: s){
            int value = it - 'a' + 1;
            if(value>=10){
                sum+= value%10 + value/10; 
            }else
                sum = sum + value; 
        }

        k--;//since I did the sum once;
        while(k-- && sum>=10){//furthur trasformations starts here
            sum = sumDigits(sum);
        } 
        return sum;
    }
};