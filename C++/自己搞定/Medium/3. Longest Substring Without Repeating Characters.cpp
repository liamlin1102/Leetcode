#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


//這題思路，如果你想用迴圈來解決會被制裁。
//要怎麼求最長的subarray，用sliding window，一路往右把遇到的加到map裡，如果map裡面有東西，代表重複了
//此時調整左邊的位置，一路找到重複英文字母的位置，這樣就可以確保這個sliding window是以重複的數字之後一個數
class Solution {
public:
    int lengthOfLongestSubstring_bad(string s) {
        if(s.size()==1||s.size()==0){
            return s.size();
        }
        unordered_map<char,int> checkRepeat; int longestLen=0;int nowLen=0;int left=0;int right=0;
        while(right<s.size()){
            //如果發現它在裡面
            if(checkRepeat.contains(s[right])){
                //維護最大長度，代表重複的遇到了，要結算目前的長度
               longestLen = max(longestLen,nowLen);
               //當左邊小於右邊(因為最慘就是倒數第二)，一定會找到重複
               while(left<=right){
                    //移除map裡面的值
                    checkRepeat.erase(s[left]);
                    //維護長度
                    nowLen--;
                    //如果發現遇到重複的停下來，長度就在這裡
                    if(s[left++]==s[right]){
                        break;
                    }
               } 
            }
            //其他狀況，加入map
            checkRepeat[s[right]]+=1;
            right++;
            nowLen+=1;
        }
        //有可能最後一步還是有可能一路不重複，所以出來維護一下
        longestLen = max(longestLen,nowLen);
        return longestLen;
    }
    int lengthOfLongestSubstring_smart(string s) {
        unordered_map<char,int> numIndex;int nowLen=0;int answer=0;int left=0;
        //更簡單的方法，既然都用map了，那為什麼不直接把位置存下來，這樣只要重複的點 比現在的left近，我就維護總長度
        //為什麼呢舉個例子，aabaab，此時在index = 2 的時候，b存在index=2 aindex = 1
        //此時到index=5的時候，b存在index=2 aindex=4，但此時我在b遇到重複，她維護長度會用 5-2 = 3 ，但中間明明有兩個a，不是正確的
        //因此我每次遇到重複，都需要維護left，如果重複的值儲存位置在left的更左邊，代表中間有違規string ，因此維護長度是要用left去維護
        for (int index=0;index<s.size();index++){
            if(numIndex.contains(s[index])){
                //因為重複遇到了維護答案
                answer=max(answer,nowLen);
                //此時去看left跟儲存的重複值得位置靠右，用靠右的那個當開始計算新字串的位置
                left = max(left,numIndex[s[index]]);
                //去維護長度，現在的位置等等會在下面新增所以-1(因為left是不算現在的位置的)
                nowLen = index-left-1;1
            }
            numIndex[s[index]]=index;
            nowLen++;
        }
        answer=max(answer,nowLen);
        return answer;
    }
};