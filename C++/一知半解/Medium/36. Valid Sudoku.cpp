#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
using namespace std;

//這題的思路就是數學，要怎麼iterate 3*3 的square，讓你知道是否有重複，那要如何知道?最簡單的方法就是去定義出你現在的數字在第幾格
//用row/3*3+col/3可以算出第幾格，這種算法會是從左至右3，從上至下  0 1 2
//                                                            3 4 5
//                                                            6 7 8 
//或是用col/3*3+row/3，這種算法也一樣如上述圖片，遍歷確定符合條件即可
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char,int> countNum;
        for (int col=0;col<9;col++){
            for (int row=0;row<9;row++){
                char num = board[row][col];
                if(countNum.contains(num)){
                    return false;
                }
                if(num!='.'){
                    countNum[num]=1;   
                }
            }
            countNum.clear();  
        } 
        for (int row=0;row<9;row++){
            for (int col=0;col<9;col++){
                char num = board[row][col];
                if(countNum.contains(num)){
                    return false;
                }
                if(num!='.'){
                    countNum[num]=1;   
                }
            }
            countNum.clear();  
        } 
        map<int,map<char,int>> sudoBlock={
                    {0,{}},
                    {1,{}},
                    {2,{}},
                    {3,{}},
                    {4,{}},
                    {5,{}},
                    {6,{}},
                    {7,{}},
                    {8,{}},
                };
        for (int row=0;row<9;row++){
            for (int col=0;col<9;col++){
                int sudoBlockNum = row/3*3+col/3;
                char num = board[row][col];
                if(num!='.'){
                    if(sudoBlock[sudoBlockNum].contains(num)){
                        return false;
                    }
                    sudoBlock[sudoBlockNum][num] = 1;
                }
            }
        } 
        return true;
    }
};