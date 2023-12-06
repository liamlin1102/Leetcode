#include<iostream>
#include <bits/stdc++.h>
#include <vector>
//這題很難，沒想出來，看解答懂得，他跟two pointer那題很像，差別在two pointer是看兩邊中間能裝多少水，因此不用判斷中間
//但這題是看長條圖每個bar最大的空間，所以要判斷中間，此時我們要做的事情只有兩個，一個是當我們遇到邊長比自己小的bar，就停下來運算面積
//這題非常複雜，下面會逐步講解
using namespace std;
class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int index = 0,maxArea = 0;
        std::stack<int> checkSmallHeight;
        //為什麼這裡要推一個0，因為我們晚點要做的事情就是，檢查下一個長度是否高過自己，如果沒有高過自己則進行運算面積
        //為了確保最後一次會進入運算面積的路線，直接推一個0進去，可以確保沒有任何東西高過他
        heights.emplace_back(0);
        //到終點前都往下
        while(index<heights.size()){
            //如果目前stack是空的或是目前的值比stack最上面的值還大，代表不用結算面積，直接把高度放進去，為什麼不用結算面積呢?
            //目前假設有一個長度 3 4 5 0 ，那是不是我們可以產生一個3*3 4*2 5*1 的大小的面積
            //我們3的時候把它加進去(0)，4的時候也把他加進去(1)，5的時候也加進去(2)，然後0的時候開始結算面積
            //我們首先把 5 取出來 此時算出來面積為 index= 3 -1(因為2pop出來，目前最上面是1) -1 * 5 = 5
            //接下來因為0還是小於4 ，把4取出來，此時算出來的面積為 index = 3 - 0(因為1 pop出來 最上面是0) -1 * 4 = 4*2
            //接下來因為0還是小於3，把3取出來，但裡面空了，所以長度直接取index = 3 * 3 = 9
            //發現嗎 ，他會一路把面積算回來，因此就要維持看到高的數值繼續往下走，遇到低於的代表你不能延伸，延伸就多算了
            if(checkSmallHeight.empty()||heights[checkSmallHeight.top()]<heights[index]){
                //只有stack是空的以及目前遇到值比已知的最小值還高才繼續存
                checkSmallHeight.emplace(index++);
            }
            else{
                //進來代表目前的高度比已存的高度還低
                //此時把最上面的index吐出來，並且去運算吐出來的index的面積
                //怎麼算面積呢，已經知道我們右邊的值比現在還低，左邊的數字一定比自己低，代表左邊的數字可以一路往右延伸，相反右邊不行延伸回去
                //只要把目前的index - 吐出來後下一個(也就是當前面積的index左邊那一個)-1 就是長度了
                //舉例還說，3 4 5 0，如果要算5的面積，3、4不該被延伸，那就是index = 3- 1(5左邊的4 是index=1) -1(因為是算長度不-1會少扣一個，導致重複運算)
                //那4的時候是不是可以延伸到5，那就是index = 3 - 0(4旁邊的3 index=0) -1 4*2
                //那3的時候左邊沒值了，就不用算了，反正總長度就是目前的index個index = 3*3
                 int nowIndex = checkSmallHeight.top();
                 checkSmallHeight.pop();
                 //這公式就是這樣來的
                 int nowArea = heights[nowIndex]*(checkSmallHeight.empty()?index:index-checkSmallHeight.top()-1);
                 maxArea = std::max(maxArea,nowArea);

            }
        }
        return maxArea;
    }
};
//拆解的方法，從左邊找最小，接下從右邊找最小邊界的index，最後把最左跟坐右的最小再找最小，最後就是答案
class Solution {
public:
    std::vector<int> nextSmallIndex(std::vector<int> heights){
        std::stack<int> tempStack;
        tempStack.emplace(-1);
        std::vector<int> answer(heights.size());
        for(int index = heights.size()-1;index>=0;index--){
            while(tempStack.top()!=-1 && heights[tempStack.top()]>=heights[index]){
                tempStack.pop();
            }
            answer[index] = tempStack.top();
            tempStack.emplace(index);
        }
        return answer;
        
    }
    std::vector<int> prevSmallIndex(std::vector<int> heights){
        std::stack<int> tempStack;
        tempStack.emplace(-1);
        std::vector<int> answer(heights.size());
        for(int index = 0;index<heights.size();index++){
            while(tempStack.top()!=-1 && heights[tempStack.top()]>=heights[index]){
                tempStack.pop();
            }
            answer[index] = tempStack.top();
            tempStack.emplace(index);

        }
        return answer;
        
    }
    int largestRectangleArea(std::vector<int>& heights) {
        if(heights.size()==1){
            return heights[0];
        }
        int maxArea = 0; std::vector<int> nextSmallVector = nextSmallIndex(heights);
        std::vector<int> prevSmallVector = prevSmallIndex(heights);
        for(int index=0;index<heights.size();index++){
            if(nextSmallVector[index]==-1){
                nextSmallVector[index] =heights.size();
            }
            maxArea = std::max(maxArea,(nextSmallVector[index]-prevSmallVector[index]-1)*heights[index]);
        }
        return maxArea;

    }
};