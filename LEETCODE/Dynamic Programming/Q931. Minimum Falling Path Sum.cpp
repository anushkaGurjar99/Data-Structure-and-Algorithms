/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/minimum-falling-path-sum/

class Solution{
public:
    int minFallingPathSum(vector<vector<int>>& A){
        
        if(A.size() < 1)
            return 0;
        
        if(A.size() == 1)
            return A[0][0];
        
        vector<vector<int>> dp = A;
        int result = INT_MAX;
        int size = A.size();
        
        for(int i = 1; i < size; i++){
            for(int j = 0; j < size; j++){
                
                int left = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int right = (j + 1 < size) ? dp[i - 1][j + 1] : INT_MAX;
                int up = dp[i - 1][j];
                
                dp[i][j] += min(up, min(left, right));
                
                if(i == size - 1)
                    result = min(dp[i][j], result);                
            }
        }
        return result;        
    }
};

/*
Each cell will contain minimum path to reach it.
    Obtained by cell in addition with min of (upper cell, upper left cell and upper right cell)
    
That's how we will reach to bottom most path and return the minimum of bottom most row.
*/
