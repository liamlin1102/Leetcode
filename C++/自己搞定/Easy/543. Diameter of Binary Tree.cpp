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
    int countDiameter(TreeNode* curr,int &maxDiameter){
        if(!curr) return 0;
        int leftDepth = countDiameter(curr->left,maxDiameter);
        int rightDepth = countDiameter(curr->right,maxDiameter);
        maxDiameter = std::max(maxDiameter,leftDepth+rightDepth+1);
        return std::max(leftDepth,rightDepth)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        countDiameter(root,maxDiameter);
        return maxDiameter-1;        
    }
};