#include<iostream>
#include <bits/stdc++.h>
#include <vector>
//經典題目
class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int maxPiles = *std::max_element(piles.begin(), piles.end());
        if (h==piles.size()){
            return maxPiles;
        }
        int minPiles = 1;
        while(maxPiles>minPiles){
            int temp = h;
            int midPiles = minPiles+(maxPiles-minPiles)/2;           
            for(int pile :piles){
                int times =  pile%midPiles==0?pile/midPiles:pile/midPiles+1;
                temp-=times;
            }
            if(temp<0){
                minPiles = midPiles+1;
            }
            else{
                maxPiles = midPiles;
            }
        }
        return minPiles; 
    }
};