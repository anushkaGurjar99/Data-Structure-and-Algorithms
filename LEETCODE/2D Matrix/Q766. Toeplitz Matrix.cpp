/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/toeplitz-matrix/

#include<stdio.h>
using namespace std;

class Solution{
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix){
        
        deque<int> window;
        
        int col = matrix[0].size();
        int row = matrix.size();
        int r, c;
        
        for(c = 0; c < col; c++)
            window.push_back(matrix[0][c]);
        
        for(r = 1; r < row; r++){
            window.pop_back();
            
            for(c = 1; c < col; c++){
                window.push_back(matrix[r][c]);
                
                if(window.back() != window.front())
                    return false;
                
                window.pop_front();
            }
            window.push_front(matrix[r][0]);
        }
        
        return true;
    }
};

/*
Approach: Sliding Window 

Take a Deque 'window' then push 1st row in it.
Loop through all ROWS
    POP the last element of Window (last ROW last ELEMENT is expired)
    (skip first element of CURRENT ROW){
        PUSH elements of NEXT ROW in Window
        and check it's FRONT ELEMENT with BACK ELEMENT (if same continue else return false)
        POP the front element as we know it is valid DIOGNAL
    }
    push the skipped element
*/

