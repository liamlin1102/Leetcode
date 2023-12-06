#include<iostream>
#include <bits/stdc++.h>
#include <vector>


class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if(prices.size()==1){
            return 0;
        }
        int minPrice=prices[0];int answer=0;
        for(int price:prices){
            if(price>=minPrice){
                answer = std::max(price-minPrice,answer);
            }
            else{
                minPrice = price;
            }
        }
        return answer;
    }
};