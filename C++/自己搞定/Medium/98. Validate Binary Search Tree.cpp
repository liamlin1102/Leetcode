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

//利用往左走時調整不能超過的最大值，往右走調整不能小於的最小值來找出是否符合，但要帶樹進去，不然為int overflow
class Solution {
public:
    bool isValidBST(TreeNode* root,TreeNode* minTree,TreeNode* maxTree){
        if(!root)return true;
        
        if((minTree &&  root->val<=minTree->val) || (maxTree && root->val>=maxTree->val))return false;
        return isValidBST(root->left,minTree,root) && isValidBST(root->right,root,maxTree);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,nullptr,nullptr);
    }
};
//最值觀，直接用Inorde走訪，一路大小是asending就是沒問題
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};