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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> answer ;
        if(!root)return answer;
        std::vector<int>temp;
        std::queue<TreeNode*> treeQueue({root});
        TreeNode* curr ;
        while(!treeQueue.empty()){
            int lenQueue = treeQueue.size();
            for(int count=0;count<lenQueue;count++){
                curr =treeQueue.front();
                treeQueue.pop();
                temp.emplace_back(curr->val);
                if(curr->left)treeQueue.emplace(curr->left);
                if(curr->right)treeQueue.emplace(curr->right);                
            }
            answer.emplace_back(temp);
            temp.clear();            
        }
        return answer;
    }
};