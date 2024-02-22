#include<iostream>
#include <bits/stdc++.h>
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
    int helper(TreeNode* root,int minNum,int maxNum){
        if(!root){
            return abs(maxNum-minNum);
        }
        minNum = std::min(minNum,root->val);
        maxNum = std::max(maxNum,root->val);
        return std::max(helper(root->left,minNum,maxNum),helper(root->right,minNum,maxNum));
    }
    int maxAncestorDiff(TreeNode* root) {
        return this->helper(root,root->val,root->val);
    }
};