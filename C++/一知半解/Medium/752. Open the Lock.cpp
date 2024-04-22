#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;
//這題是圖的經典題 要記得求最短就是用BFS 有點像樹


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //來檢查是否撞到死亡數字
        std::unordered_set<std::string> mapDead(deadends.begin(),deadends.end());
        //有可能dedends裡面一開始就有0000直接不用玩
        if (mapDead.contains("0000")) return -1;
        //BFSqueue
        std::queue<std::string> numQue;
        //用來檢查有沒有重複過,為什麼需要呢?假設我今天0000到1111 結果在1111 又有機會回到0000 那這個queue永遠有東西 因此要檢查
        std::unordered_set<std::string> checkDup;
        int answer=0;
        //直接把起點放進去
        numQue.emplace("0000");
        checkDup.emplace("0000");
        //如果不為空
        while(!numQue.empty()){
            //看這個level有幾個,也可以直接新增一個queue放 後面在取代 但我不喜歡那種作法
            int curLevel = numQue.size();
            for(int count= 0;count<curLevel;count++){
                std::string nowNum = numQue.front();
                //如果是答案就直接回傳
                if(nowNum==target) return answer;
                numQue.pop();
                //如果沒找到 就把四碼各調1的狀況
                //這裡就是核心了 為什麼各調1可以覆蓋所有狀況?
                //很簡單 你先丟了1000進去 在1000被抓出來處理的時候 又會有2000 1100等如此類推
                //因此可以當作對每個digit都有兩個node是相鄰的 一個往下 一個往上 那當然就要把各種可能放進queue裡
                for(int digit=0;digit<4;digit++){
                    string plusNum = this->plusNum(nowNum,digit);
                    string minusNum = this->minusNum(nowNum,digit);
                    if(!checkDup.contains(plusNum)&& !mapDead.contains(plusNum)){
                        numQue.emplace(plusNum);
                        checkDup.emplace(plusNum);
                    }
                    if(!checkDup.contains(minusNum) && !mapDead.contains(minusNum)){
                        numQue.emplace(minusNum);
                        checkDup.emplace(minusNum);
                    }
                }

            }
            answer++;
        }
        return -1;
    }
    std::string plusNum(std::string nowNum,int digit){
        if (nowNum[digit]=='9') nowNum[digit]='0';
        else nowNum[digit]++;//酷酷的算法原來可以這樣
        return nowNum;

    }
    std::string minusNum(std::string nowNum,int digit){
        if (nowNum[digit]=='0') nowNum[digit]='9';
        else nowNum[digit]--;
        return nowNum;
    }
};