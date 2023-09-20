#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<std::string>> groupAnagrams(std::vector<string>& strs) {
        if (strs.size()==1||strs.size()==0){
            vector<vector<string>> answer;
            answer.push_back(strs);
            return answer;        
        }
        map<vector<int>,vector<string>> mapTemp;
        for(auto str:strs){
            vector<int> vecTemp(26,0);
            for(auto word:str){
                vecTemp[(int)word-(int)'a']+=1;
            }
            for(auto it:vecTemp){
                cout<<(char)it<<endl;
            }
            if (mapTemp.contains(vecTemp)){
                mapTemp[vecTemp].push_back(str);
            }
            else{
                vector<string> strTemp={str};
            }
        }
        vector <vector<string>> answer;
        for (auto pair : mapTemp) {
            answer.push_back(pair.second);
        }
        return answer;
    }
};