//思路就是左右去維護最大值，並且去確認哪邊比較長，比較短的那一邊先結算水池是否增加，結算後持續移動
//因為有維護最大值，因此只要目前的值比當前的最大值小，就一定有水池，由於水池達成條件是兩邊最小那邊為主
//此時為了要知曉左邊右邊誰才是相對最大，比方說
// [0,1,0,2,1,0,1,3,2,1,2,1]，如果沒有去維護右邊，左邊走到3後往右走就會開始3-2、3-1、3-2.....，這顯然是不對的因為3右邊沒有更大的值不符合用3當最小邊的算法
//因此這題就是維護左右最大值，並且讓左右小的那邊持續移動，這樣就可以保證左右交會的點是全地圖的最高點，就可以做到用左右邊的相對最大值去對其真的最大值來算水池
#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        //由於每次移動前會結算水池，因此都預設為0
        int left=0;int right=height.size()-1;int answer=0;int maxLeft=0;int maxRight=0;
        while (right>left){
            //如果右邊比左邊大，代表此時右邊是默認的全場最大值，左邊就是相對的最大，因此左邊往右走，用左邊的最大值來計算水窪絕不可能錯
            if(height[right]>height[left]){
                if(maxLeft>height[left]){
                    //如果此時左邊的相對最大值比現在的位置大，但表有水窪
                    answer+=(maxLeft-height[left]);
                }
                else{
                    //如果沒有代表變高了，不僅沒有水窪還要調整左邊最大值
                    maxLeft = height[left];
                }
                left++;
            }
            else{
                //如果兩邊一樣大或是右邊比較大(反正一樣挑一邊走即可)，代表此時左邊是默認的全場最大值，右邊就是相對的最大，因此右邊往左走，用右邊的最大值來計算水窪絕不可能錯
                if(maxRight>height[right]){
                    //如果此時右邊的相對最大值比現在的位置大，但表有水窪
                    answer+=(maxRight-height[right]);
                }
                else{
                    //如果沒有代表變高了，不僅沒有水窪還要調整右邊最大值
                    maxRight = height[right];
                }
                right--;
            }
        }
        return answer;
        
    }

};
