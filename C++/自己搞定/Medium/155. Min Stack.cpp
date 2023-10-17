#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;
//這題其實跟montonic一樣但題目要求實作O(1)，因此只能犧牲空間了
//我們做一個正常的stack，以應付一般stack的需求，同時做另一個minStack只做min的需求
//因為stack的特性是LIFO，因此我們可以保證前面的值一定比後面的所有值，因此我們只需要做一件事情
//我們一旦更新了最小值，就把新的最小值推到minStack裡面，因為後面加入的最小值才有機會先被pop出去
//因此我們只需要在push的時候檢查最小值是否被更新，同時Pop的時候檢查目前的最小值有沒有被pop即可
class MinStack {
public:
    std::stack<int> normalStack;
    std::stack<int> minStack; 
    MinStack() {
        
    }
    
    void push(int val) {
        normalStack.emplace(val);
        if(minStack.empty()||minStack.top()>=val){
            minStack.emplace(val);
        }
        
    }
    
    void pop() {
        if(normalStack.top()==minStack.top()){
            minStack.pop();
         }
         normalStack.pop();
    }
    
    int top() {
        return normalStack.top();
        
    }
    
    int getMin() {
        return minStack.top();
        
    }
};
