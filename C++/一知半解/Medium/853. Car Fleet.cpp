#include<iostream>
#include <bits/stdc++.h>
#include <map>

//這題設計的挺差的..我原先以為後面的數字是一個單位，大家都過一小時看有沒有交會，後來發現不是是去看半路有沒有追到
//那就換個角度想唄，用長度/速度=需要時間，當後面的車需要的時間比前面的短，那就可以跟他合併啦
//然後就遇到我唯一錯的地方了，我原先以為一定要小於，想說等於的話你開始的位置比較後面一定追不到，後面才發現，我有考量空間算出來一樣代表他們會在終點相遇
//所以是要算的

//這題還有另一個小缺點，double運算有精度的問題，要馬用decimal 要馬用乘法
class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        std::vector<std::pair<int,double>> vecPair(position.size());
        int fleets=position.size();
        for(int index =0;index<position.size();++index){
            vecPair[index].first = position[index];
            vecPair[index].second = (double)(target-position[index])/(double)speed[index];         
        }
        std::sort(vecPair.rbegin(),vecPair.rend());
        double preTimes = 0.0;
        for(int index =0;index<vecPair.size();++index){
            if(index!=0){
                double nowTimes = vecPair[index].second;
                if(nowTimes<=preTimes){
                    --fleets;
                    continue;
                }
            }
            preTimes = vecPair[index].second;

        }
        return fleets;     
    }
};