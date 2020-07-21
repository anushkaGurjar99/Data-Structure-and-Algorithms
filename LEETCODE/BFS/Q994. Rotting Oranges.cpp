/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/rotting-oranges/

class Solution{
public:
    int orangesRotting(vector<vector<int>>& grid){
        
        int result = 0;
        if(isZeroFreshOrange(grid))
            return 0;
        
        queue<pair<int, int>> q = getBaseRotten(grid);
        if(q.size() == 0)
            return -1;
        
        while(!q.empty()){
            for(int i = q.size(); i > 0; i--){
                pair<int, int> curr = q.front();
                q.pop();
                check(curr.first - 1, curr.second, grid, q);
                check(curr.first + 1, curr.second, grid, q);
                check(curr.first, curr.second - 1, grid, q);
                check(curr.first, curr.second + 1, grid, q);
            }
            result++;
        }
        
        if(isAnyOrangeLeft(grid))
            return -1;
        
        return --result;
    }
    
    queue<pair<int, int>> getBaseRotten(vector<vector<int>>& grid){
        queue<pair<int, int>> q;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 2)
                    q.push({r, c});
            }
        }
        return q;
    }
    
    bool isZeroFreshOrange(vector<vector<int>>& grid){
        for(auto row: grid){
            for(auto col: row){
                if(col == 1)
                    return false;
            }
        }
        
        return true;
    }
    
    void check(int r, int c, vector<vector<int>>& grid, queue<pair<int, int>>& q){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
            return;
        
        if(grid[r][c] == 1){
            grid[r][c] = 2;
            q.push({r, c});
        }
    }
    
    bool isAnyOrangeLeft(vector<vector<int>>& grid){
        for(auto row: grid){
            for(auto col: row){
                if(col == 1)
                    return true;
            }
        }
        
        return false;
    }
};

/*
    Notice:
        Case1: If there is no Fresh orange;
        Case2: If there is no Rotten oranges;
        Case3: After processing if there is Any fresh orange left; (due to inaccessibility). Ex:        
                    [[2],
                     [2],
                     [1],
                     [0],
                     [1],
                     [1]]
                     
Processing Rotten:  In BFS Manner;
                    Initally store all the rotten oranges into Q;
                    In each iteration process the whole Q and update the result;
                    
Note: If there is any leftOver fresh orange, that should be rotten: this can be checked after processing only, check above ex.
*/
