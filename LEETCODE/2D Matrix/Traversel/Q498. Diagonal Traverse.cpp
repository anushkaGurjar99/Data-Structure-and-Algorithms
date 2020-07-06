/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/diagonal-traverse/

class Solution{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix){
        
        if(matrix.size() < 1)
            return {};
        
        int limit = matrix.size() + matrix[0].size() - 1;
        int row = 0;
        int col = 0;
        
        vector<int> result;
        
        while(limit > 0){
            //cout<<"\n"<<row<<" "<<col;
            moveUpwards(matrix, result, row, col);
            
            //cout<<"\t"<<row<<" "<<col;
            if(limit - 1 > 0)
                moveDownwards(matrix, result, row, col);
            
            limit -= 2;
        }
        
        return result;
    }
    
    void moveUpwards(vector<vector<int>>& matrix, vector<int>& result, int& row, int& col){
        while(row >= 0 && col < matrix[0].size()){
            result.push_back(matrix[row][col]);
            row--;
            col++;
        }
        
        row++, col--;                                               // restore prev
        (col + 1 < matrix[0].size()) ? col++ : row++;               // calc next
    }
    
    void moveDownwards(vector<vector<int>>& matrix, vector<int>& result, int& row, int& col){
        while(row < matrix.size() && col >= 0){
            result.push_back(matrix[row][col]);
            row++;
            col--;
        }
        
        row--, col++;                                               // restore prev
        (row + 1 < matrix.size()) ? row++ : col++;                  // calc next
    }
};

/*
Observation:
    We only need ROWS + COLS - 1  iterations to cover all cells
    

Now follow this: 
    So start from first cell [0][0]    (direction UP)
        move as UP as possible
        
        then update the pointer for DOWN
            case 1: If we have more cols we can move to next COL 
            case 2: If we have more rows we can move to next ROW


    We go to DOWN direction
        move as DOWN as possible 
        
        then update the pointer for UP
            case 1: If we have more rows we can move to next ROW
            case 2: If we have more cols we can move to next COL 
*/




/********************************************************************************************************

other ways are covered in Diagonal Traverse II



