/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        
        if(matrix.size() < 1)
            return {};
        
        int row = 0;
        int col = 0;
        int csize = matrix[0].size() - 1;
        int rsize = matrix.size() - 1;
            
        vector<int> result;
        
        while(row <= matrix.size()/2 && col <= csize){
            
            int i;
            
            if(row <= rsize - row){
                for(i = col; i <= (csize - col); i++)                        // top
                    result.push_back(matrix[row][i]);
            }
            
            if(col <= csize - col){
                for(i = row + 1; i <= (rsize - row); i++)                    // right
                    result.push_back(matrix[i][csize - col]);
            }
                
            if(rsize - row > row){
                for(i = csize - col - 1; i >= col; i--)                     // bottom
                    result.push_back(matrix[rsize-row][i]);            
            }
            
            if(csize - col > col){
                for(i = rsize - row - 1; i >= row + 1; i--)                  // left
                    result.push_back(matrix[i][col]);
            }
            
            row++, col++;
        }
        
        return result;
    }
};

/*
Check if the corrosponding ROW or COL is in Range(using the IF cond.)
If it is then visit the cells
TOP : visit all cells
RIGHT : visit all cells (except TOP)
BOTTOM : visit all cells (except TOP)
LEFT: visit all cells (except TOP and BOTTOM)
*/
