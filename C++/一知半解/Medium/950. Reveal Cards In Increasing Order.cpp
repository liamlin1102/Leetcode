#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;


//這題是我沒體驗過的題
//它的核心方法就是用模擬的方式
//什麼是模擬的方式？我們需要將12345 轉成翻盤後的樣子
//那不就代表我只要模擬1 2 3 4 5 然後操作翻盤後的樣子
//放置對應的點就會是答案了
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int cardNum = deck.size();
        std::sort(deck.begin(),deck.end());//排序
        std::deque<int> simulator;//因為我們要把第二張放到最後
        std::vector<int> answer(cardNum,0);//答案會跟deck一樣
        for(int index=0;index<cardNum;index++){
            simulator.emplace_back(index);//排數字 對應的就是answer的index
        }
        for(auto card:deck){
            //把模擬當前第一張的數字放最小的牌
            answer[simulator[0]] = card;
            //因為放進去了所以刪掉
            simulator.pop_front();
            //把第二張(當前的第一張)取出來
            int putCard = simulator[0];
            //刪掉
            simulator.pop_front();
            //放到最後一張
            simulator.emplace_back(putCard);
        }
        return answer;      
    }
}; 