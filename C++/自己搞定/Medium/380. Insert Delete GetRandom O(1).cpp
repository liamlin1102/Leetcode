#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

class RandomizedSet {
    std::unordered_map<int,int> mapNums;
    std::vector<int> vecNums;
public:
    RandomizedSet() {
        srand(time(NULL)); 
    }
    
    bool insert(int val) {     
        if(!mapNums.contains(val)) {
            vecNums.emplace_back(val);
            mapNums[val] = vecNums.size()-1;
            return true;
        };
        return false;     
    }
    
    bool remove(int val) {
        if(mapNums.contains(val)) {
            std::swap(vecNums[vecNums.size()-1],vecNums[mapNums[val]]);
            mapNums[vecNums[mapNums[val]]] = mapNums[val];
            vecNums.pop_back();
            mapNums.erase(val);
            return true;
        };
        return false;    
    }
    
    int getRandom() {
       return vecNums[rand()%vecNums.size()];
    }
};