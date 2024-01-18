#include<iostream>
#include <bits/stdc++.h>
#include <vector>
//這題有點麻煩，絲路就是透過 preorder去找出左、右子樹，一路往下切，切後再慢慢新增樹回來，但如果直接SLICE很不好
//因此就帶數字進去，把每次切的開始跟結束位置找出來，好題目值得一做在做
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

//這題如果把map帶進去不call pointer會TLE，並且變數的vector也是要注意
class Solution {
    std::unordered_map<int,int> inoderIndexMap;
public:
//preStart要帶參考，如果不帶就要自行透過preEnd以及inoStart、End回推正確位置
    TreeNode* findTree(std::vector<int>& preorder, std::vector<int>& inorder,int& preStart,int preEnd,int inoStart,int inoEnd){
        if(preStart>preEnd || inoStart>inoEnd) return nullptr;
        int sliceIndex = inoderIndexMap[preorder[preStart]];
        return new TreeNode(preorder[preStart++],
        findTree(preorder,inorder,preStart,preEnd,inoStart,sliceIndex-1),
        findTree(preorder,inorder,preStart,preEnd,sliceIndex+1,inoEnd));
    }
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        int index = 0;
        int length = preorder.size()-1;
        for(int index =0;index<inorder.size();index++){
            inoderIndexMap[inorder[index]] = index;
        }
        return findTree(preorder,inorder,index,length,0,length);
    }
};