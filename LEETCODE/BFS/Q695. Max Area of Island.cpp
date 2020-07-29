/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/max-area-of-island/

class Solution{
public:
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int result = 0;
        
        if(grid.size() < 1)
            return result;
        
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1){
                    int currArea = 0;
                    bfs(grid, r, c, currArea);
                    result = max(result, currArea);
                }
            }
        }
        
        return result;
    }
    
    void bfs(vector<vector<int>>& grid, int row, int col, int& currArea){
        if(OOB(row, col, grid.size(), grid[0].size()) || grid[row][col] != 1)
            return;
        
        grid[row][col] = 2;
        currArea++;
        
        bfs(grid, row + 1, col, currArea);
        bfs(grid, row - 1, col, currArea);
        bfs(grid, row, col + 1, currArea);
        bfs(grid, row, col - 1, currArea);
    }
    
    bool OOB(int row, int col, int rowSize, int colSize){
        if(row < 0 || col < 0)
            return true;
        if(row >= rowSize || col >= colSize)
            return true;
        
        return false;
    }
};

/*
Simple BFS, keep counting all connected 1s and update the result.
*/
