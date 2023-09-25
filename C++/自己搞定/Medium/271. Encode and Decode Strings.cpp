#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

//這題思路，有兩種解法一種是直接去找不在256 ASCII code的變數(例如markdown的表情符號)，來當作split的點
//另一個就是直接把，有幾個數字，分別長度加在表頭。進入到decode在解析

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) 
    {
        string encodeStr="";
        string infoStr=to_string(strs.size())+"^";
        for(string str:strs){
            infoStr+=to_string(str.size())+"^";
            encodeStr+=(str+"^");
        }
        encodeStr.pop_back();
        encodeStr = infoStr+encodeStr;
        return encodeStr;
    }

    vector<string> decode(string &str) 
    {
        vector<string> answer;
        map<int,int> counts;
        string tempStr="";
        int lenStrs = 0;
        int count=1;
        int stratIndex=0;
        bool first = true;
        for(int index=0;index<str.size();index++)
        {
            if (str[index]=='^')
            {
                if(first){
                    first =false;
                    lenStrs =stoi(tempStr);                  
                }
                else if(count<=lenStrs){
                    counts[count] = stoi(tempStr);
                    count++;
                    if(count>lenStrs)
                    {
                        stratIndex = index+1;
                    }
                }
                tempStr = "";
            }
            else if(stratIndex!=0)
            {
                for(int i =1 ;i<=lenStrs;i++)
                {
                    int lenStr =counts[i];
                    answer.push_back(str.substr(stratIndex,lenStr));
                    stratIndex+=lenStr+1;
                }
                break;
            }
            else
            {
                tempStr+=str[index];
            }
        }
        return answer; 
    }
};
int main(){
    Solution sol;
    vector<string> test{"15w","sds","wew889"};
    string te = sol.encode(test);
    cout<<te;
    vector<string> answer  = sol.decode(te);
    for (auto i : answer){
        cout<<i<<endl;
    }
}