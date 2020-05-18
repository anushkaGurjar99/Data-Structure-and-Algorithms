/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/path-with-maximum-gold/

class Solution{
public:
    int getMaximumGold(vector<vector<int>>& grid){
        
        int result = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] != 0)
                    backtrack(grid, result, r, c, 0);
            }
        }
        
        return result;
    }
    
    void backtrack(vector<vector<int>>& grid, int& result, int row, int col, int currSum){
        if(row < 0 || row >= grid.size())
            return;
        
        if(col < 0 || col >= grid[0].size())
            return;
        
        if(grid[row][col] == 0)
            return;
        
        currSum += grid[row][col];
        result = max(result, currSum);
        
        int temp = grid[row][col];
        grid[row][col] = 0;
        
        backtrack(grid, result, row - 1, col, currSum);         // up
        backtrack(grid, result, row + 1, col, currSum);         // down
        backtrack(grid, result, row, col - 1, currSum);         // left
        backtrack(grid, result, row, col + 1, currSum);         // right
        
        grid[row][col] = temp;
    }
};

/*
Intution:
We can only visit one way path so for each path we must have currSum (sum of all the tiles in path)
From all the visited path get the MaxSumPath.

    - mark the non-zero cell 0 (just to exclude visited tile in grid)
    - visit all non-zero cell path (maintain a maximum and currSum)
    - restore the original
*/
