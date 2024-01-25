#include<iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int answer= 0;
        int lastSecond = -1;
        for(int second : timeSeries){
            if(second<=lastSecond){
                answer+= second-lastSecond+duration-1>0?second-lastSecond+duration-1:0;
            }
            else{
                answer+=duration;
            }
            lastSecond =second+ duration-1 ;
        }
        return answer;
    }
};