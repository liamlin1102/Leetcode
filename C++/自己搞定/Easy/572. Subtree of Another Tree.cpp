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

//每個點都比比看，有一樣的救回傳
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)return true;
        else if(!p || !q)return false;
        else if(p->val!=q->val)return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)return false;
        if(isSameTree(root,subRoot))return true;
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};

//反過來的思維，既然下面有東西就不算，那我就從最下面開始找，遇到頭是一樣的財確認是否一樣，是就一路回傳
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)return true;
        else if(!p || !q)return false;
        else if(p->val!=q->val)return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)return false;
        bool boolLeft = isSubtree(root->left,subRoot);
        bool boolRight = isSubtree(root->right,subRoot);
        if(boolLeft||boolRight)return true;
        if(root->val==subRoot->val) {
            return isSameTree(root,subRoot);
        }
        return boolLeft||boolRight;
    }
};