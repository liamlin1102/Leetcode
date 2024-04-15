#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    int answer;
public:
    int helper(TreeNode* root,std::string tempNum){
        if(!root) return 0 ;
        tempNum+=to_string(root->val);
        if(!root->left && !root->right){
            size_t startIndex = tempNum.find_first_not_of('0');
            return (startIndex == std::string::npos) ? 0 :std::stoi(tempNum.substr(startIndex));
        }
        return this->helper(root->left,tempNum)+this->helper(root->right,tempNum);  
     
    }

    int sumNumbers(TreeNode* root){
        answer = 0;
        return this->helper(root,"");
    }
};