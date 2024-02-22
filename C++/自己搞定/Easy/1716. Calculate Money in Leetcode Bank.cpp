#include<iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int totalMoney(int n) {
        int week = n/7;
        int lessDay = n%7;
        int weekMoney = 7*8/2;
        int answer= 0;
        for(int count = 0;count<week;count++){
            answer+=weekMoney+7*count;
        }
        if(lessDay){
            answer+=lessDay*(lessDay+1)/2 + week*lessDay;
        }
        return answer;
    }
};