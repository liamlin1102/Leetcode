#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        std::unordered_set<std::string> answer;
        for(std::string email : emails){
            int atIndex = 0;
            for(int index = 0;index<email.size();index++){
                if(email[index]=='@'){
                    atIndex = index;
                }
            }
            std::string localName = email.substr(0,atIndex);
            std::string domainName = email.substr(atIndex+1,email.size()-atIndex-1);
            std::string realLocalName = "";
            for (char word : localName){
                if(word=='+'){
                    break;
                }
                if(word!='.'){
                    realLocalName+=word;
                }
            }
            string temp = realLocalName+"@"+domainName;
            answer.insert(temp);
        }
        return answer.size();
    }
};