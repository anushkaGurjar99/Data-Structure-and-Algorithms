/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid){
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> table(row, vector<int>(col, 0));
        
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                table[r][c] = grid[r][c] + getMinimumPathSum(table, r, c);
            }
        }
        
        return table[row - 1][col - 1];
    }
    
    int getMinimumPathSum(vector<vector<int>>& table, int& row, int& col){
        int upCost = INT_MAX;
        int leftCost = INT_MAX;
        
        if(row > 0)
            upCost = table[row - 1][col];
        
        if(col > 0)
            leftCost = table[row][col - 1];
        
        return (upCost == INT_MAX && leftCost == INT_MAX) ? 0 : (upCost < leftCost) ? upCost : leftCost;   
    }  
};

/*
    For each cell calculate the Minimum Cost Path - 
        min(leftDirectionPath, upDirectionPath) + cost of current cell
        Case: if none direction exist(assume cost = 0)
        Case: if any one path exist (take existing)
        Case: if both path exist (choose the minimum)
        
    at last return the bottom-right cell.
*/
