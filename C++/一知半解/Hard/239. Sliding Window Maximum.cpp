#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <deque>
using namespace std;

//這題思路很簡單，但我寫道LTE，所以要更了解montonic stack的觀念
//要記得，我們維護montonic stack除了確保最裡面是最大值外，還要把之前比他小的每一個都刪掉
//這同時表示什麼，因為montonic的設定，比最大值晚進來的值會不管大小在他後面，因此我們pop左邊的值根本不需要搜索整個Montonic 
//我們只需要檢查最大值如果符合，代表這個是在左邊沒被擠掉的，如果不是，那他早就被擠掉了沒差。你不用去找他

//示意圖，[3,4,5,1,2,6,9,10,11,7,12],deque<int> mq;
//首先，把3加進去，好mq={3},再把4加進去(從前面加)，此時發現3比4小，把3刪掉，mq={4}，接下來一樣，5進去，mq={5}
//然後插入1，1比5小，擠不出去，因此mq={1,5},再來2，他比1大但比5小，把1擠掉,mq={2,5},6跟9跟10跟11就不一樣了
//6比2、5大，此刻2、5會被擠出去。mq={6},然後到11前都一樣， mq={11},然後7比11小，mq={7,11},最後12加入，mq={12}
//有發現嗎，單調維護的montonic stack，從前面加入，會不斷保證最後一個是最大值，此時如果我長度設定為2字串在1、2的時候
//mq長什麼樣子，他長成{1,5}，此時要移除的5會在最後面，其他的都會被前面擠出去用這個思路即可


class MontonicQueues{
    private:
        std::deque<int> montonicQueues;
    public:
        //最大值等於最後一個
        int max(){
            return montonicQueues.back();
        }
        //推進去才要處理，如果是空的直接推進去，跳出
        void push(int num){
            if (montonicQueues.empty()){
                montonicQueues.emplace_front(num);
                return ;
            }
            //不是空的且目前最前面的數字還比當前數字小，代表可以把他擠掉
            while(!montonicQueues.empty() && montonicQueues.front()<num){
                //把他擠掉
                montonicQueues.pop_front();
            }
            //擠完後把他加入正確的位置
            montonicQueues.emplace_front(num);
        }
        //照剛剛說的，要被移除的只有最大值還在的地方，更新的時候在檢查，是最大值的話把它移除
        void pop(int num){
            if(num == montonicQueues.back()){
                montonicQueues.pop_back();
            }
        }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left=0;int right =0;std::vector<int> answer;MontonicQueues montonicQueue;
        if (nums.size()==k){
            int maxNum = *max_element(nums.begin(),nums.end());
            answer.emplace_back(maxNum);
            return answer;
        }
        for(int index=0;index<k;index++){
            montonicQueue.push(nums[index]);
        }

        answer.emplace_back(montonicQueue.max());
        for(right=k;right<nums.size();right++){
            montonicQueue.pop(nums[left]);
            montonicQueue.push(nums[right]);
            answer.emplace_back(montonicQueue.max());
            ++left;
        }
        return answer;        
    }
};

class Solution {
public:
    void push(int num,deque<int>& montonicQueues){
        vector<int> tempVec;
        if(montonicQueues.empty() || montonicQueues.back()<=num){
            montonicQueues.emplace_back(num);
            return;
        }
        int mright = montonicQueues.size()-1;int mleft = 0;int target = 0;
        while(mright>mleft){
            int mid = mleft+(mright-mleft)/2;
            if(montonicQueues[mid]>num){
                mright = mid;
            }
            else{
                mleft = ++mid;
            }
            target = mleft;
        }
        montonicQueues.emplace(montonicQueues.begin()+target,num);
        return;
    }
    void pop(int num,deque<int>& montonicQueues){
        vector<int> tempVec;
        if(montonicQueues.empty()){
            return;
        }
        if(montonicQueues.back()==num){
            montonicQueues.pop_back();
            return;
        }
        if(montonicQueues.front()==num){
            montonicQueues.pop_front();
            return;
        }
        int mright = montonicQueues.size()-1;int mleft = 0;int target = 0;
        while(mright>=mleft){
            int mid = mleft+(mright-mleft)/2;
            if(montonicQueues[mid]>num){
                mright = --mid;
            }
            else if(montonicQueues[mid]<num){
                mleft = ++mid;
            }
            else if(montonicQueues[mid]==num){
                target = mid;
                break;
            }
        }
        montonicQueues.erase(montonicQueues.begin()+target);
        return;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left=0;int right =0;std::deque<int> montonicQueues;std::vector<int> answer;
        if (nums.size()==k){
            int maxNum = *max_element(nums.begin(),nums.end());
            answer.emplace_back(maxNum);
            return answer;
        }
        for(int index=0;index<k;index++){
            push(nums[index],montonicQueues);
        }

        answer.emplace_back(montonicQueues.back());
        for(right=k;right<nums.size();right++){
            // cout<<montonicQueues.front()<<endl;
            pop(nums[left],montonicQueues);
            push(nums[right],montonicQueues);
            answer.emplace_back(montonicQueues.back());
            ++left;
        }
        return answer;        
    }
};