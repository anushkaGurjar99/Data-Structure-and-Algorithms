/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/island-perimeter/

class Solution{
public:
    int islandPerimeter(vector<vector<int>>& grid){
        
        int result = 0;
        
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1)
                    result += getBoundary(grid, r, c);
            }
        }
        
        return result;
    }
    
    int getBoundary(vector<vector<int>>& grid, int row, int col){
        
        int count = 0;
        
        if(row - 1 < 0 || grid[row - 1][col] == 0)
            count += 1;
        
        if(col - 1 < 0 || grid[row][col - 1] == 0)
            count += 1;
        
        if(row + 1 == grid.size() || grid[row + 1][col] == 0)
            count += 1;
        
        if(col + 1 == grid[0].size() || grid[row][col + 1] == 0)
            count += 1;
        
        return count;
    }
    
};

/*
Approach:
    If cell == 1,
        check its 4 adjecent cell values (left, right, top and bottom)
            if cell 1:  we don't need any doundary
            else     :  we need to add boundary     
*/


