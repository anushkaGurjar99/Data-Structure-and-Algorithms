/*
 * Author : Anushka Gurjar
 * Date   : October 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/number-of-closed-islands/

class Solution{
public:
    int closedIsland(vector<vector<int>>& grid){
        
        int res = 0;
        
        for(int i = 1; i < grid.size(); i++){
            for(int j = 1; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    bool flag = true;
                    dfs(grid, i, j, flag);
                    res += flag ? 1 : 0;
                }
            }
        }
        
        return res;
    }
    
    void dfs(vector<vector<int>>& A, int r, int c, bool& flag){
        if(r < 0 || c < 0)
            return;
        
        if(r >= A.size() || c >= A[0].size())
            return;
        
        if(A[r][c] != 0)
            return;
        
        if(r == 0 || c == 0 || r == A.size() - 1 || c == A[0].size() - 1)
            flag = false;
        
        A[r][c] = 2;
        
        dfs(A, r - 1, c, flag);
        dfs(A, r, c - 1, flag);
        dfs(A, r + 1, c, flag);
        dfs(A, r, c + 1, flag);
    }
};

/*
    Go through the matrix
        If any island cell found
            mark that whole island visited
            check if any island cell is boundary cell (Yes->count 0, No->count 1)
            update result
*/

