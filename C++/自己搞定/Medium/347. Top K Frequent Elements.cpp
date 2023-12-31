#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution_smart {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mapCounts;
        for(const auto num : nums){
            if(mapCounts.contains(num)){
                mapCounts[num]+=1;
            }
            else{
                mapCounts[num] = 1;
            }
        }
        priority_queue<pair<int,int>> pq ;
        for(const auto pair:mapCounts){
            pq.push({pair.second,pair.first});
        }
        vector<int> ans ;
        int index=1;
        while(index<=k){
            ans.push_back(pq.top().second);
            pq.pop();
            index++;
        }
        return ans;
    }
};

class Solution_bad {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> countMap;
        vector<int> answer;
        for(const auto num:nums){
            if(!countMap.contains(num)){
                countMap[num]=1;
            }
            else{
                countMap[num]+=1;
            }
            bool isLive;
            int index = 0;
            for(int i=0;i<answer.size();i++){
                if (answer[i]==num){
                    isLive=true;
                    index= i-1;//不跟自己比所以減1
                    break;
                }
                else{
                    isLive=false;
                }
            }
            int len=0;
            if(isLive){
                len = index;
            }
            else{
                len = answer.size()-1;
            }

            while(len>=0 && !answer.empty()){
                if(countMap[answer[len]]>=countMap[num]){
                    break;
                }
                len--;  
            }
            if(answer.empty()){
                answer.push_back(num);
            }
            else if(isLive){
                answer.insert(answer.begin()+len+1,num);
                answer.erase(answer.begin()+index+2);
            }
            else{
                answer.insert(answer.begin()+len+1,num);
            }

            if(answer.size()>k){
                answer.pop_back();
            }       
        }
        return answer;
    }
};