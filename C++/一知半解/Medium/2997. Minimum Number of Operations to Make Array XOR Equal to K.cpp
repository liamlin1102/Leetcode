
#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

//這題很吃觀念,要知道什麼是bit
//這題雖然說什麼最小換位元次數 每個都可以換 但其實根本不重要 
//因為2分只有2跟1因此我發現這個數字不對的時候 我只要隨便找一個相關的位元修改就好
//所以就是逐個檢查 不一樣就加一 一樣但是整體不一樣就要過他 代表這一位不用調
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xNums = 0;
        int count = 0;
        for(int num : nums){
            //這邊可以算出整個
            xNums = xNums ^ num;
        }
        while(xNums||k){
            //檢查最後一位
            if(xNums%2!= k%2){
                count++;
            }
            else if(xNums==k){
                break;
            }
            //往右移
            xNums/=2;
            k/=2;
        }
        return count;
    }
};