
#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;


//這題沒搞懂 想很久還是沒想出來 結果是用一種巧思解出來
//我們把所有的英文字母都攤開來.然後在每一個節點去找 這個節點可包含的所有字母 把所有的字母都統計玩 就看哪個字母被呼叫最多次 
class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[27] = {0};
        int n = s.length();

        for (int i = n - 1; i >= 0; i--) {
            char cc = s[i];
            int idx = cc - 'a';
            int maxi = -__INT_MAX__;

            int left = max((idx - k), 0);
            int right = min((idx + k), 26);

            for (int j = left; j <= right; j++) {
                maxi = max(maxi, dp[j]);
            }

            dp[idx] = maxi + 1;
        }

        int max = -__INT_MAX__;
        for (int i = 0; i < 27; i++) {
            if (dp[i] > max)
                max = dp[i];
        }

        return max;
    }
};