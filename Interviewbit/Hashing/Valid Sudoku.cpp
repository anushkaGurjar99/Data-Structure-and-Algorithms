/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/valid-sudoku


int Solution::isValidSudoku(const vector<string> &board) {

    vector<vector<bool>> row(9, vector<bool> (9, false));
    vector<vector<bool>> col(9, vector<bool> (9, false));
    vector<vector<bool>> block(9, vector<bool> (9, false));
        
    for(int r = 0; r < 9; r++){            
        for(int c = 0; c < 9; c++){
    
            if(board[r][c] == '.')
                continue;
                
            int val = board[r][c] - '1';
            int box = (r / 3) * 3 + (c / 3);

            if(row[r][val] || col[c][val] || block[box][val])
                return false;

            row[r][val] = col[c][val] = block[box][val] = true;
        }
    }
    
    return true;
}
