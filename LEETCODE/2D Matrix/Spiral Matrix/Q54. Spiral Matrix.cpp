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
Check if the corrosponding ROW or COL is in Range(using the IF cond.) (FOR ALL DIRECTIONS)
TOP : visit all cells
RIGHT : visit all cells (except TOP)
BOTTOM : visit all cells (except TOP)
LEFT: visit all cells (except TOP and BOTTOM)
*/

// ******************************************* Using Switch and Enum ****************************************

class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        if(matrix.size() < 1)
            return {};
        
        enum dir{RIGHT, DOWN, LEFT, UP};
        
        vector<int> res;
        int limit = matrix.size()*matrix[0].size();

        int rowBegin = 0;
        int rowEnd = matrix.size();
        int colBegin = 0;
        int colEnd = matrix[0].size();

        int r = 0;
        int c = 0;
        dir direction = RIGHT;

        while(res.size() < limit){
            
            switch(direction){
                
                case RIGHT:{
                    while(c < colEnd){
                        res.push_back(matrix[r][c]); 
                        c++; 
                    }
                    r++;
                    c--;
                    direction = DOWN;
                }
                break;
                    
                case DOWN:{
                    while(r < rowEnd){
                        res.push_back(matrix[r][c]); 
                        r++; 
                    }
                    r--;
                    c--;
                    direction = LEFT;
                }
                break;

                case LEFT:{
                    while(c >= colBegin){
                        res.push_back(matrix[r][c]); 
                        c--; 
                    }
                    r--;
                    c++;
                    direction = UP;
                }
                break;
                    
                case UP:{
                    while(r > rowBegin){
                        res.push_back(matrix[r][c]);
                        r--;
                    }
                    r++;
                    c++;
                    rowBegin++;
                    colBegin++;
                    rowEnd--;
                    colEnd--;
                    direction = RIGHT;
                }
                break;
            }
        }
        return res;
    }
};

