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
//iterate
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(true){
            if(p->val>root->val && q->val>root->val){
                root = root->right;
            }
            else if(p->val<root->val && q->val<root->val){
                root = root->left;
            }
            else{
                return root;
            }
        }
        return nullptr;
    }
};

//recrusive
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val>p->val && root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val<p->val && root->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};

//有趣的版本，沒注意到題目說BST，這個方法是不是bst也可以
class Solution {
public:
    TreeNode* CheckFindNode(TreeNode* root, TreeNode* p, TreeNode* q,bool& meetNode) {
        if(!root)return root;
        if(root==p){
            meetNode = true;
            return p ;
        }
        if(root==q){
            meetNode = true;
            return q;
        }
        bool leftMeetNode = false;
        bool rightMeetNode = false;
        TreeNode* leftStoreNode = CheckFindNode(root->left,p,q,leftMeetNode);
        TreeNode* rightStoreNode = CheckFindNode(root->right,p,q,rightMeetNode);      
        if(leftMeetNode && rightMeetNode){
            meetNode = true;
            return root;
        }
        if(leftMeetNode){
            meetNode = true;
            return leftStoreNode;
        }
        if(rightMeetNode){
            meetNode = true;
            return rightStoreNode;            
        }
        return leftStoreNode;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool meetNode = false;
        return CheckFindNode(root,p,q,meetNode);
    }
};
