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
    bool checkPalindromic
    int helper(TreeNode* root,std::vector<int> countArray){
        if(!root){
            int count =0;
            for(auto num:countArray){
                if(num==1) count++;
            }
            return count<=1?1:0;
        }
        countArray[root->val-1]++;
        return helper(root->left,countArray)+helper(root->right,countArray);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return helper(root,std::vector<int>(0,9));
    }
};