#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    //插花小遊戲，如果當前是0並且上一個是0或是第一個，以及後一個是0或是最後一個,把答案-0 若最後小於0return 0 ，並把它變成1
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        for (int place=0;place<flowerbed.size();place++){
            if(flowerbed[place]==0 && (place==0||flowerbed[place-1]!=1)&&(place==flowerbed.size()-1||flowerbed[place+1]!=1)){
                if(--n<=0) return true;
                flowerbed[place] = 1;
            }
        }
        return false;      
    }
};

//greedy，直接只要是0 我就檢查前後
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for(int i = 0; i < flowerbed.size() && count < n; i++) {
            if(flowerbed[i] == 0) {
	     //get next and prev flower bed slot values. If i lies at the ends the next and prev are considered as 0. 
               int next = (i == flowerbed.size() - 1) ? 0 : flowerbed[i + 1]; 
               int prev = (i == 0) ? 0 : flowerbed[i - 1];
               if(next == 0 && prev == 0) {
                   flowerbed[i] = 1;
                   count++;
               }
            }
        }
        
        return count == n;
    }
};