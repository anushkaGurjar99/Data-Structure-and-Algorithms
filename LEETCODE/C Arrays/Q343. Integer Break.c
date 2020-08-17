/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/integer-break/

int integerBreak(int n){    
    
    if(n <= 3)
        return n - 1;
    
    int dp[n][n + 1];
    
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
        for(int j = 1; j <= n; j++)
            dp[i][j] = 0;
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= n; j++){
            int product = (j - i < 0) ? 0 : dp[i][j - i] * i;
            dp[i][j] = fmax(dp[i - 1][j], product);
        }
    }
    
    return dp[n - 1][n];
}

/*
    DP Solution: (same as coin change)
    
        0   1   2   3   4   5   6   
    0   1   0   0   0   0   0   0
    1   1   1   1   1   1   1   1
    2   1   1   2   2   2   4   4
    3   1   1   2   3   3   6   9
    4   1   1   2   3   4   6   9
    5   1   1   2   3   4   6   9
    
    
    target = 6
*/


