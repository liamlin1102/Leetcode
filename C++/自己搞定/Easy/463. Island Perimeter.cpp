
#include<iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;


class Solution {
public:
    int check(vector<vector<int>>& grid,int width,int height){
        int answer= 0;
        if(width==0|| grid[height][width-1]==0){
            answer++;
        }
        if(width==grid[0].size()-1||grid[height][width+1]==0){
            answer++;
        }
        if( height==0||grid[height-1][width]==0){
            answer++;
        }
        if(height==grid.size()-1||grid[height+1][width]==0){
            answer++;
        }
        return answer;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int answer = 0;
        for(int height = 0;height<grid.size();height++){
            for(int width = 0;width<grid[0].size();width++){
                if (grid[height][width]==1){
                    answer+=check(grid,width,height);
                }
            }
        }
        return answer;
    }
};
