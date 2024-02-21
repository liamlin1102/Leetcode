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
    int recrusive(TreeNode* root,int& answer) {
        if(!root)return 0;
        int leftNum = recrusive(root->left,answer);
        int rightNum = recrusive(root->right,answer);
        int maxNum = leftNum>rightNum?leftNum:rightNum;
        answer = std::max(answer,leftNum+rightNum+root->val);
        if(root->val+maxNum<=0) return 0;
        else return root->val+maxNum;
    }
    int maxPathSum(TreeNode* root) {
        int leftAnswer = -INT32_MAX;
        int rightAnswer = -INT32_MAX;
        int leftSum = recrusive(root->left,leftAnswer);
        int rightSum = recrusive(root->right,rightAnswer);
        int answer = std::max(leftAnswer,rightAnswer);
        return std::max(leftSum+rightSum+root->val,answer);
    }
};