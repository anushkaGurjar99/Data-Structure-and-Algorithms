/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/maximal-square/

class Solution{
public:
    int maximalSquare(vector<vector<char>>& matrix){
        
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        
        int result = 0;
        
        // scan 1st row
        for(int c = 0; c < matrix[0].size(); c++){
            if(matrix[0][c] == '1'){
                result = 1;
                break;
            }
        }
        
        // scan 1st col
        if(result == 0){
            for(int r = 0; r < matrix.size(); r++){
                if(matrix[r][0] == '1'){
                    result = 1;
                    break;
                }
            }
        }
        
        for(int r = 1; r < matrix.size(); r++){
            for(int c = 1; c < matrix[0].size(); c++){
                if(matrix[r][c] == '1'){             
                    int top = matrix[r - 1][c] - '0';
                    int left = matrix[r][c - 1] - '0';
                    int diognal = matrix[r - 1][c - 1] - '0';
                    
                    matrix[r][c] = '0' + 1 + min(top, min(left, diognal));
                    
                    int t = matrix[r][c] - '0';
                    result = max(t, result);
                }
            }
        }
        
        return result * result;
    }
};

// similar to Q1277.
