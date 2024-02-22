#include<iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        int answer = 0;
        while(n>1){
            answer+=n/2;
            n = n%2==0?n/2:n/2+1;
        }
        return answer;      
    }
};