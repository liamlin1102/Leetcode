#include<iostream>
#include <bits/stdc++.h>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };



class Solution {
public:
    int storeMax(TreeNode* root,int maxNodeValue){
        if(!root){
            return 0;
        }
        if(root->val>=maxNodeValue){
            return storeMax(root->left,root->val)+storeMax(root->right,root->val)+1;    
        }
        else{
            return storeMax(root->left,maxNodeValue)+storeMax(root->right,maxNodeValue);   
        }
    }
    int goodNodes(TreeNode* root) {
        return storeMax(root,root->val);
        
    }
};