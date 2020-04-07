/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        
        if(matrix.size() < 1)
            return false;
        
        int row = 0;
        int col = matrix[0].size() - 1;
        
        while(row < matrix.size() && col >= 0){
            
            if(matrix[row][col] > target)
                col--;
            else if(matrix[row][col] < target)
                row++;
            else 
                return true;
        
        }
        
        return false;
    }
};

/*
Start from Top-Right corner,
  If the cell value is Greater than target -> Move left
  Else If the cell value is Less than target -> Move bottom
  Else (Return true as target found) 
  
Exit if you run out of cells and return false;
*/
