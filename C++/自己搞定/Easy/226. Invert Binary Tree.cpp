#include<basetsd.h>
#include<iostream>
#include<deque>

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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        std::deque<TreeNode*> treeDeque{root};
        TreeNode* temp = nullptr;
        TreeNode* curr = nullptr;
        while(!treeDeque.empty()){
            curr = treeDeque.front();
            treeDeque.pop_front();
            if(curr->left)treeDeque.emplace_back(curr->left);
            if(curr->right)treeDeque.emplace_back(curr->right);
            temp = curr->left;
            curr->left =curr->right;
            curr->right = temp;      
        }
        return root;
    }
};