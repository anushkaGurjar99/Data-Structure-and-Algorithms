/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/longest-common-subsequence/

int longestCommonSubsequence(char *one, char *two){
    
    int rows = strlen(one);
    int cols = strlen(two);
    int dp[rows + 1][cols + 1]; 
    
    for(int i = 0; i <= rows; i++)
        dp[i][0] = 0;
    
    for(int i = 0; i <= cols; i++)
        dp[0][i] = 0;
    
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            dp[i + 1][j + 1] = (one[i] == two[j]) ? (dp[i][j] + 1) : fmax(dp[i + 1][j], dp[i][j + 1]);
    }
    
    return dp[rows][cols];
}

/*
    Note:   2D array declaration.
*/
