#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int answer = 0;
        int lessTime = tickets[k];
        for(int index = 0;index<tickets.size();index++){
            int diff = 0;
            if(index>k) diff = -1;
            if(tickets[index]<lessTime) answer += tickets[index];
            else answer += lessTime+diff;
        }
        return answer;     
    }
};