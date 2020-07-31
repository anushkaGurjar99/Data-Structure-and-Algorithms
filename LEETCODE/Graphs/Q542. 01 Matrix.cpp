/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++17
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/01-matrix/

class Solution{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix){
        queue<pair<int, int>> q;
        vector<vector<int>> result(matrix.size(), vector<int>(matrix[0].size(), -1));
        
        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; c < matrix[0].size(); c++){
                if(matrix[r][c] == 0){
                    q.push({r, c});
                    result[r][c] = 0;
                }
            }
        }
        
        int steps = 1;
        
        while(!q.empty()){
            for(int i = q.size(); i > 0; i--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                helper(result, steps, row, col, q);
            }
            
            steps++;
        }
        
        return result;
    }
    
    void helper(vector<vector<int>>& result, int steps, int r, int c, queue<pair<int, int>>& q){
        if(r - 1 >= 0 && result[r - 1][c] == -1){
            q.push({r - 1, c});
            result[r - 1][c] = steps;
        }
        
        if(c - 1 >= 0 && result[r][c - 1] == -1){
            q.push({r, c - 1});
            result[r][c - 1] = steps;            
        }
        
        if(r + 1 < result.size() && result[r + 1][c] == -1){
            q.push({r + 1, c});
            result[r + 1][c] = steps;
        }
        
        if(c + 1 < result[0].size() && result[r][c + 1] == -1){
            q.push({r, c + 1});
            result[r][c + 1] = steps;
        }
    }
};


/*
    Approach 1: DFS (TLE)
    
    Appraoch 2: 
        store all the zero pos in queue.
        
        while q is not empty
            visit all q elements
                for each zero cell ->   check all 4 directions in matrix
                                        if any of the 4 is '-1' 
                                            then initliaze cell to STEPS
                                            store this one into q
    
    Note ->
        STEPS will increment in each step ( 1, 2, 3, and so on...)
        -1 denotes that we haven't visit this cell yet so 


SOME examples (-1 is replaces to -) =>

    -   0   -                   1   0   1
    -   -   -           =>      -   1   -
    -   0   -                   1   0   1
    
    
    -   -   -                   -   -   -               -   2   -
    -   -   -           =>      -   1   -       =>      2   1   2
    -   0   -                   1   0   1               1   0   1
*/


// *************************************************************************** DFS ***************************************************************************
class Solution{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix){
        
        if(matrix.size() < 1)
            return {};
        
        vector<vector<int>> result (matrix.size(), vector<int>(matrix[0].size(), 0));
        
        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; c < matrix[0].size(); c++){
                if(matrix[r][c] == 1){
                    int steps = INT_MAX;
                    dfs(matrix, result, steps, 0, r, c);
                    result[r][c] = steps;
                }
            }
        }
        
        return result;
    }
    
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& result, int& ans, int curr, int r, int c){
        if(r < 0 || c < 0)
            return;
        
        if(r == matrix.size() || c == matrix[0].size())
            return;
        
        if(result[r][c] != 0){                                  // if cost for current cell is already calculated
            ans = min(ans, curr + result[r][c]);
            return;
        }
        
        if(matrix[r][c] == 0){
            ans = min(ans, curr);
            return;
        }
        
        curr++;
        
        if(matrix[r][c] == 1){
            matrix[r][c] = -1;

            dfs(matrix, result, ans, curr, r + 1, c);
            dfs(matrix, result, ans, curr, r, c + 1);
            dfs(matrix, result, ans, curr, r - 1, c);
            dfs(matrix, result, ans, curr, r, c - 1);

            matrix[r][c] = 1;
        }
        
    }
};

/*
    : search all 4 direction in each iteration (keep counting the cost)
      store the minimum of all into result.
*/

