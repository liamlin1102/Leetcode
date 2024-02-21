#include<iostream>
#include <bits/stdc++.h>
#include <vector>
//簡單邏輯題中毒後會有幾回合
using namespace std;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int answer= 0;
        //計算上一回合的秒數
        int lastSecond = -1;
        //看攻擊間隔
        for(int second : timeSeries){
            //如果目前的秒數小於等於上一次地的秒數
            if(second<=lastSecond){
                //代表目前的答案要加上的值是目前的時間-上次的時間+中毒持續時間如果大於0就加上那個值，如果小於0那就持續中毒
                //上次已經把該值運算完畢了
                answer+= second-lastSecond+duration-1>0?second-lastSecond+duration-1:0;
            }
            else{
                //把持續時間直接加上去
                answer+=duration;
            }
            //中毒持續秒數到幾秒
            lastSecond =second+ duration-1 ;
        }
        return answer;
    }
};