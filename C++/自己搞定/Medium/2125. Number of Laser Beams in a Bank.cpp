#include<iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int lastLaser = 0;
        int answer = 0;
        for (string lasers : bank){
            int thisRowLaser = 0;
            for(char laser : lasers){          
                if (laser=='1') ++thisRowLaser;
            }
            if(lastLaser && thisRowLaser) answer+=(thisRowLaser*lastLaser); 
            lastLaser = thisRowLaser==0?lastLaser:thisRowLaser;
        }
        return answer;
    }
};