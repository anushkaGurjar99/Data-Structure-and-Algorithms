/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/number-of-islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid){
        
        if(grid.size() == 0)
            return 0;
        
        int numberOfIsland = 0;
        
        for(int row = 0; row < grid.size(); row++){
            
            for(int col = 0; col < grid[row].size(); col++){
                
                if(grid[row][col] == '1'){
                    
                    numberOfIsland++;
                    queue<pair<int,int>> waterArea;
                    waterArea.push({row,col});
                    grid[row][col] = '2';                   // to remove cycles
                    
                    
                    // removing the area connected by water current point
                    while(!waterArea.empty()){
                        pair<int,int> current = waterArea.front();
                
                        waterArea.pop();
                        
                        int r = current.first;
                        int c = current.second;
                        
                        // remove bottom area
                        r++;
                        while(r < grid.size() && grid[r][c] == '1'){
                            grid[r][c] = '2';
                            waterArea.push({r,c});
                            r++;
                        }
                        
                        r = current.first; // restore row intex
                        
                        // remove left area
                        c--;
                        while(c >= 0 && grid[r][c] == '1'){
                            grid[r][c] = '2';
                            waterArea.push({r,c});
                            c--;
                        }
                        
                        c = current.second; // restore col index
                        
                        // remove top area
                        r--;
                        while(r >= 0 && grid[r][c] == '1'){
                            grid[r][c] = '2';
                            waterArea.push({r,c});
                            r--;
                        }
                        
                        r = current.first; // restore row intex
                        
                        // remove right area
                        c++;
                        while(c < grid[r].size() && grid[r][c] == '1'){
                            grid[r][c] = '2';
                            waterArea.push({r,c});
                            c++;
                        }
                    }
                        
                }   
            }
        }
        
        return numberOfIsland;
    }
};


// **************************************** BFS + DFS ********************************************************
// BFS for traversal, DFS for removal

class Solution {
public:
    int numIslands(vector<vector<char>>& grid){
        
        if(grid.size() == 0)
            return 0;
        
        int numberOfIsland = 0;
        
        for(int row = 0; row < grid.size(); row++){
            
            for(int col = 0; col < grid[row].size(); col++){
                    
                    if(grid[row][col] == '1'){
                        numberOfIsland++;
                        coverArea(grid, row, col);
                    }
            }
        }
        
        return numberOfIsland;
    }
    
    void coverArea(vector<vector<char>>& grid, int row, int col){
        
        // if row number is not in range
        if(row == grid.size() || row < 0)
            return;
        
        // if column number is not in range
        if(col < 0 || col == grid[row].size())
            return;
        
        if(grid[row][col] == '1'){
            grid[row][col] = '2';

            coverArea(grid, row-1, col);          // top
            coverArea(grid, row+1, col);          // bottom
            coverArea(grid, row, col-1);          // left
            coverArea(grid, row, col+1);          // right
        }
        
    }
};
