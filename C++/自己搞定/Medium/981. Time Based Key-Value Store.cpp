#include<iostream>
#include <bits/stdc++.h>
#include <map>
//這題不難，但莫名會TLE...可能不能用map<string,map<int,string>>的格式，要用 map<string,vector<pair<int,string>>會比較快
class TimeMap {
private:
    std::map<std::string,std::vector<std::pair<int,std::string>>> answer;
public:
    TimeMap() {
        
    }
    
    void set(std::string key, std::string value, int timestamp) {
        answer[key].emplace_back(timestamp,value);
        
    }
    
    std::string get(std::string key, int timestamp) {
        if(!answer.contains(key)){
            return "";
        }
        int right = answer[key].size();int left = 0;
        if(timestamp<answer[key][left].first){
            return "";
        }
        while(right>left){
            int mid = left+(right-left)/2;
            if(answer[key][mid].first ==timestamp){
                return answer[key][mid].second;
            }
            else if(answer[key][mid].first>timestamp){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return answer[key][left-1].second;
    }
};


class TimeMap {
private:
    std::unordered_map<std::string,std::map<int,std::string>> answer;
public:
    TimeMap() {
        
    }
    
    void set(std::string key, std::string value, int timestamp) {
        answer[key][timestamp] = value;
        
    }
    
    std::string get(std::string key, int timestamp) {
        // auto valueMap = answer[key]; 多了這一行就會直接超時...我也不知道為什麼..
        auto it=answer[key].upper_bound(timestamp);
        if(it==answer[key].begin())return "";
        it--;
        return it->second;
     }
};