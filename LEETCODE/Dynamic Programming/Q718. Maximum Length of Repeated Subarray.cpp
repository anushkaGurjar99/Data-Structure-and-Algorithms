/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/maximum-length-of-repeated-subarray/

class Solution{
public:
    int findLength(vector<int>& A, vector<int>& B){
        
        vector<vector<int>> dp(A.size(), vector<int> (B.size(), 0));
        int result = 0;
        
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < B.size(); j++){
                
                int diognal = (i > 0 && j > 0) ? dp[i - 1][j - 1] : 0;                
                dp[i][j] = (A[i] == B[j]) ? diognal + 1: 0;
                result = max(dp[i][j], result);
                
            }
        }
        
        return result;
    }
};

// remember we want subarray not subset
