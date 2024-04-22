
#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    std::string helper(TreeNode* root,std::string& minStr,std::string nowStr){
        if(!root) return "";
        nowStr = char('a'+root->val)+nowStr;
        if(!root->left && !root->right){
            if(minStr=="") minStr=nowStr;
            else minStr=min(minStr,nowStr);
        }
        helper(root->left,minStr,nowStr);
        helper(root->right,minStr,nowStr);
        return minStr;
    }

    string smallestFromLeaf(TreeNode* root) {
        std::string answer = "";
        return helper(root,answer,"");
    }
};