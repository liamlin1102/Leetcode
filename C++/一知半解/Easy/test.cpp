
#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

string MissingDigit(string str) {
  int opeIndex = 0;
  char ope ;
  int equalndex = 0;
  int xIndex = 0;
  string first = "";
  string second = "";
  string third = "";
  string temp = "";
  for(int index=0;index<str.size();index++){
    if(str[index]-'0'>=0 || str[index]-'0'<=9 ){
      temp+=str[index];
    }
    if(str[index]=='*'||str[index]=='+'||str[index]=='-'||str[index]=='/'){
      ope = str[index];
      opeIndex = index;
      first = temp;
      temp="";
    }
    else if (str[index]=='x'){  
      xIndex = index;
    }
    else if(str[index]=='='){
      equalndex = index;
      second = temp;
      temp="";
    }
  }
  third = temp;
  string com="";
  string xStr = "";
  cout<<third;
  if(xIndex>opeIndex && xIndex>equalndex){
    xStr = third;
    if(ope=='*'){
      com = std::stoi(first)*std::stoi(second);
    }
    else if(ope=='/'){
      com = std::stoi(first)/std::stoi(second);
    }
    else if(ope=='-'){
      com = std::stoi(first)-std::stoi(second);
    }
    else{
      com = std::stoi(first)+std::stoi(second);
    }
  }
  else if(xIndex>opeIndex && xIndex<equalndex){
    xStr = second;
    if(ope=='*'){
      com = std::stoi(third)/std::stoi(first);
    }
    else if(ope=='/'){
      com = std::stoi(first)/std::stoi(third);
    }
    else if(ope=='-'){
      com = std::stoi(first)-std::stoi(third);
    }
    else{
      com = std::stoi(third)-std::stoi(first);
    }
  }
  else{
    xStr = first;
    if(ope=='*'){
      com = std::stoi(third)/std::stoi(second);
    }
    else if(ope=='/'){
      com = std::stoi(third)*std::stoi(second);
    }
    else if(ope=='-'){
      com = std::stoi(second)+std::stoi(third);
    }
    else{
      com = std::stoi(third)-std::stoi(second);
    }
  }
  for(int index=0;index<xStr.size();index++){
    if(xStr[index]=='x'){
      return string(1,com[index]);
    }
  }
  return string(1,com[0]);

}

int main(void) { 
    cout<<MissingDigit("4 - 2 = x")<<endl;
}