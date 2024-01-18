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
//queue版本，比deque快一點，大同小異    
class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> answer{}; 
        std::queue<TreeNode*> treeNodeQue;
        if(root) treeNodeQue.emplace(root);
        TreeNode* curr ;
        while(!treeNodeQue.empty()){
            int len = treeNodeQue.size();
            answer.emplace_back(treeNodeQue.back()->val);
            for(int count =0; count<len;count++){
                curr =treeNodeQue.front();
                treeNodeQue.pop(); 
                if(curr->left)treeNodeQue.emplace(curr->left); 
                if(curr->right)treeNodeQue.emplace(curr->right);   
            }

        }
        return answer;
    }
};
//recrusive版本，用inorder解決(但是先看右邊的inorder)
class Solution {
    std::vector<int> answer;
public:
    std::vector<int> PreorderRight(TreeNode* root,int level){
        if(!root) return answer;//一路往左
        if(answer.size()<level) answer.emplace_back(root->val);//中
        PreorderRight(root->right,level+1);//右邊
        return PreorderRight(root->left,level+1);

    }
    std::vector<int> rightSideView(TreeNode* root) {
        return PreorderRight(root,1);
    }
};


class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> answer{}; 
        if(!root)return answer;
        else answer.emplace_back(root->val);
        std::deque<TreeNode*> treeNodeDeque{root};
        std::deque<TreeNode*> temp;
        TreeNode* curr ;
        while(!treeNodeDeque.empty()){
            curr =treeNodeDeque.front();
            treeNodeDeque.pop_front();   
            if(curr->left)temp.emplace_back(curr->left);    
            if(curr->right)temp.emplace_back(curr->right); 
            if(treeNodeDeque.empty()){
                if(!temp.empty())answer.emplace_back(temp.back()->val);
                treeNodeDeque = temp;
                temp.clear();
            }
        }
        return answer;
    }
};