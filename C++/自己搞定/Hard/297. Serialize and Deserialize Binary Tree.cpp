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
class Codec {
    std::vector<std::string> splitString(std::string data){
        std::vector<std::string> answer ;std::string temp="";
        for(char word : data){
            if(word =='^'){
                answer.emplace_back(temp);
                temp="";
            }
            else{
                temp+=word;
            }
        }
        return answer;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "N^";
        std::string temp = "";
        temp+=std::to_string(root->val)+'^';
        temp+=serialize(root->left);
        temp+=serialize(root->right);
        return temp;
    }
    TreeNode* recrusive(std::vector<std::string>& data,int& index) {
        if(data[index]=="N") return nullptr;
        TreeNode* curTree = new TreeNode(std::stoi(data[index]));
        index++;
        curTree->left = recrusive(data,index);
        index++;
        curTree->right =  recrusive(data,index);
        return curTree;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        std::vector<std::string> sString = splitString(data);
        return recrusive(sString,index);     
    }
};