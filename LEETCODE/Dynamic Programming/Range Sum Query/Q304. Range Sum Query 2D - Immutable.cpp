/*
 * Author : Anushka Gurjar
 * Date   : October 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix{
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix){
        int rows = matrix.size();
        if(rows == 0)
            return;
        
        int cols = matrix[0].size();
        if(cols == 0)
            return;
        
        dp.resize(rows + 1, vector<int>(cols + 1));
        
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++)
                dp[r + 1][c + 1] = dp[r][c + 1] + dp[r + 1][c] - dp[r][c] + matrix[r][c];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2){
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
};

/*

    3	3	4	8	10	
    8	14	18	24	27	
    9	17	21	28	36	
    13	22	26	34	49	
    14	23	30	38	58 
    
Approach:
    get sum of all squares in the DP array. (shown above)
    
    to calculate sum of any subarray ->
        get the sum of last corner and remove the sum of (upper unwanted rect and left unwanted rect)
*/


