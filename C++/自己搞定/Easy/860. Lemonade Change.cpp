#include<iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int tenCoin = 0;
        int fiveCoin = 0;
        for(int bill : bills){
            if(bill==20){
                if(tenCoin>0 && fiveCoin>0) {
                    tenCoin--;
                    fiveCoin --;
                }
                else if(fiveCoin>2){
                    fiveCoin-=3;
                }
                else{
                    return false;
                }
            }
            else if(bill==10){
                if(!(fiveCoin>0))
                    return false;
                --fiveCoin;
                ++tenCoin;
            }
            else{
                ++fiveCoin;
            }
        }
        return true;
    }
};