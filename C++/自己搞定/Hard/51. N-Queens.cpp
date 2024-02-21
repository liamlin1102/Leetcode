#include<iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkRule(std::vector<std::string>& chessBoard,int row ,int columnIndex)
    {
        int limitRowSize = row;
        int limitColumnSize = chessBoard[0].size()-1;
        int count = 0;
        while(count <limitRowSize)
        {
            if (chessBoard[count][columnIndex] == 'Q')
                return false;
            ++count;
        }
        count = 1;
        while (limitRowSize - count >= 0 && columnIndex - count >= 0)
        {
            if (chessBoard[limitRowSize - count][columnIndex - count] == 'Q')
                return false;
            ++count;
        }
        count = 1;
        while (limitRowSize - count >= 0 && columnIndex + count <= limitColumnSize)
        {
            if (chessBoard[limitRowSize - count][columnIndex + count] == 'Q')
                return false;
            ++count;
        }
        return true;
    }
    void BackTracking(int n,int row ,std::vector<std::string>& chessBoard,std::vector<std::vector<std::string>>& answer){
        if(row==n){
            answer.emplace_back(chessBoard);
            return ;
        } 
        for(int column =0 ; column<n;column++){
            chessBoard[row][column] = 'Q';
            if(checkRule(chessBoard,row,column)){
                BackTracking(n,row+1,chessBoard,answer);
            }
            chessBoard[row][column] = '.';
        }
        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> answer;
        std::vector<std::string> chessBoard(n, std::string(n, '.'));
        BackTracking(n,0,chessBoard,answer);
        return answer;
    }
};