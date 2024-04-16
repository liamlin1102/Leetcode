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
public:
    void helper(TreeNode* root, int val, int depth,int nowDepth){
        if(!root) return;
        if(depth == ++nowDepth){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            root->left = new TreeNode(val,left,nullptr);
            root->right = new TreeNode(val,nullptr,right);
        }
        helper(root->left,val,depth,nowDepth);
        helper(root->right,val,depth,nowDepth);
        return ;        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth==1) return new TreeNode(val,root,nullptr);
        helper(root,val,depth,1);
        return root;
    }
};