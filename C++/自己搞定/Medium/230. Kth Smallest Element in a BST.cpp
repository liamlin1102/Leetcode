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
int answer = 0;
int count = 1;
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root)return answer;
        kthSmallest(root->left,k);
        if(count++==k)answer = root->val;       
        return kthSmallest(root->right,k);            
    }
};