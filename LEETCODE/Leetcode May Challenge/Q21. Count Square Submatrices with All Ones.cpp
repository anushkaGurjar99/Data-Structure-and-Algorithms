/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution{
public:
    int countSquares(vector<vector<int>>& matrix){
        
        int result = 0;
        
        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; c < matrix[0].size(); c++){
                if(matrix[r][c] == 1)
                    result += getCellSquareCount(matrix, r, c, 0);
            }
        }
        
        return result;
    }
    
    int getCellSquareCount(vector<vector<int>>& matrix, int& row, int& col, int limit){
        
        if(row + limit == matrix.size() || col + limit == matrix[0].size())
            return 0;
        
        int c = col + limit;
        int r = row;
        for(; r <= row + limit; r++){                               // validate right border
            if(matrix[r][c] != 1)
                return 0;
        }
        
        r = row + limit;
        for(c = col; c <= col + limit; c++){                        // validate bottom border
            if(matrix[r][c] != 1)
                return 0;
        }
        
        return 1 + getCellSquareCount(matrix, row, col, limit + 1);
    }
};

/*
Intution:
    For each cell which contains 1 we count it as square and recurse this way :-
    Note: we will only move in Right and Bottom direction for every cell
    
        Increment the side limit in each iteration 
            Return if invalid range
            Check right border
            Check bottom border
            Return 1 if all set else 0
        
    Note: Left and up border is already validated in prev iterations (undirectly), so don't check them
    
    0  [1]  1   1
    1   1   1   1  
    0   1   1   1
    
    [1] validate its right and bottom border
    increment the limit
    
    
    0  [1] [1]  1
    1  [1] [1]  1  
    0   1   1   1
    
    increment the limit
    
    
    0  [1] [1] [1]
    1  [1] [1] [1]  
    0  [1] [1] [1]
    
    reached limit.
    
    Notice that, how left and up border is auto validating.
*/
