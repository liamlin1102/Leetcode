
#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

//這題蠻難的...看解答才理解要怎麼做
//這題我原先是將我有的node放成root去模擬最短的路徑 但會TLE
//因此要反過來想 路徑是怎麼出現的 是透過Leaf一步一步往上減對吧
//leaf只會被一個node給指者 只要我們一路從leaf往上找一定會符合條件
//什麼叫符合條件? 要想喔 如果我們把leaf刪掉 上一層一定是leaf嗎?
//不一定喔 比方說 一個左邊是葉子右邊有一條樹的你把左邊跟右邊的葉子都刪掉 這樣左邊上一層的node依然也不是root
//所以要怎麼做? 還記得前面提到的 leaf只有一個關聯node 去檢查扣掉當前的node如果只剩下一個
//然後呢 最後會剩下最多兩個 為什麼是兩個 因為只要超過兩個 理論上他們一定會互連 那就會有新的leaf node
//那這樣這兩個就會下去 答案就會變回一個 所以當我們的queue長度低於2兩個 就代表答案找到了

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0}; 
        }

        unordered_map<int, vector<int>> graph;//來看看這個節點對應的所有人
        vector<int> degrees(n, 0);//用來檢查這個節點有幾個小夥伴
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
            degrees[u]++;
            degrees[v]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            //如果我發現是leaf node加入倒queue
            if (degrees[i] == 1) {
                q.push(i);
            }
        }
        //看看還剩多少個
        int remainingNodes = n;
        //低於兩個就停
        while (remainingNodes > 2) {
            int size = q.size();
            remainingNodes -= size;
            //看看所有leaf node
            for (int i = 0; i < size; i++) {
                int leaf = q.front();
                q.pop();
                for (int neighbor : graph[leaf]) {
                    degrees[neighbor]--;//把連接的node數量-1 因為要把當前的leaf扣掉
                    if (degrees[neighbor] == 1) {
                        q.push(neighbor);//如果是葉子節點推進去
                    }
                }
            }
        }
        
        vector<int> result;
        while (!q.empty()) {
            //把剩下的queue放入答案
            result.push_back(q.front());
            q.pop();
        }
        
        return result;
    }
};