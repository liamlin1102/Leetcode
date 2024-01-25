#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
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