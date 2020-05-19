/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/n-queens-ii/

class Solution{
public:
    vector<vector<string>> solveNQueens(int n){
        if(n < 1)
            return {{}};
        
        vector<string> board(n, string(n, '.'));                // fill the board with dot(.)
        vector<vector<string>> result;
        
        backtrack(board, result, 0);
        return result;
    }
    
    void backtrack(vector<string>& board, vector<vector<string>>& result, int col){
        if(col == board[0].size()){
            result.push_back(board);
            return;
        }
        
        for(int row = 0; row < board.size(); row++){
            board[row][col] = 'Q';
            if(isValid(board, row, col)){
                backtrack(board, result, col + 1);
            }
            board[row][col] = '.';
        }
    }
    
    bool isValid(vector<string>& board, int& row, int &col){
        // check col, up left, down left
        
        for(int c = col - 1; c >= 0; c--){
            if(board[row][c] == 'Q')
                return false;
        }
        
        for(int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--){
            if(board[r][c] == 'Q')
                return false;
        }
        
        for(int r = row + 1, c = col - 1; r < board.size() && c >= 0; r++, c--){
            if(board[r][c] == 'Q')
                return false;
        }
        
        return true;
    }
    
};

/*
We are placing Queen at each column
    Place queen at [row][col]                                               (row = 0 to boardSize)
    if it is a valid arrangement Backtrack (place next queens at next column)
    Else place queen to next row
    
    
    If all rows are scanned and Queen not fitting into any row
        - backtrack the last queen and shift its row position
        
        
    . . . .          Q . . .          Q Q . .          Q . . .          Q . . .          Q . Q .
    . . . .          . . . .          . . . .          . Q . .          . . . .          . . . .
    . . . .          . . . .          . . . .          . . . .          . Q . .          . Q . .
    . . . .          . . . .          . . . .          . . . .          . . . .          . . . .
    (empty board)   Q1 placed        Q2 !valid        Q2 !valid         Q2 placed       Q3 !valid
                    backtrack Q2        row++           row++           backtrack Q3    
                                        
    Q . . .          Q . . .          Q . . .          Q . . .          Q . . .          Q . Q .
    . . Q .          . . . .          . . . .          . . . .          . . . .          . . . .
    . Q . .          . Q Q .          . Q . .          . . . .          . . . .          . . . .
    . . . .          . . . .          . . Q .          . Q . .          . Q . .          . Q . .
    Q3 !valid       Q3 !valid         Q3 !valid         -----           Q2 placed       Q3 !valid
                                                    recursion ends      backtrack Q3                                        
    Q . . .          Q . . .          Q . . .          Q . . .          . . . .          . Q . .
    . . Q .          . . . .          . . . .          . . . .          Q . . .          Q . . .
    . . . .          . . Q .          . . . .          . . . .          . . . .          . . . .
    . Q . .          . Q . .          . Q Q .          . Q . .          . . . .          . . . .
    Q3 !valid       Q3 !valid         Q3 !valid         -----           Q1 placed       Q1 !valid
                                                    recursion ends      backtrack Q2
    
    
    ---------------- and this goes on till all combinations are checked ------------------
*/
