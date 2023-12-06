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
    int recrusion(TreeNode* curr,int depth){
        if(!curr)return depth;
        return std::max(recrusion(curr->left,depth+1),recrusion(curr->right,depth+1));
    }
    int maxDepth(TreeNode* root) {
        return recrusion(root,0);
    }
};