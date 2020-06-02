/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/distinct-subsequences/

int Solution::numDistinct(string A, string B){
    
    swap(A, B);
    
    vector<vector<int>> dp(A.size() + 1, vector<int> (B.size() + 1, 0));
    
    // an empty string is subsequence of all
    for(int c = 0; c <= B.size(); c++)
        dp[0][c] = 1;
    
    for(int r = 1; r <= A.size(); r++){
        for(int c = 1; c <= B.size(); c++)
            dp[r][c] = (A[r - 1] != B[c - 1]) ? dp[r][c - 1] : dp[r - 1][c - 1] + dp[r][c - 1];
    }
    
    return dp[A.size()][B.size()];
}

/*
Example:   A:  "abbaab"
           B:  "abab"
           
           Swap(A, B);              // rows denoting the target string, columns are for source string
           
                a   b   b   a   a   b
            1   1   1   1   1   1   1
        a   0   1   1   1   2   3   3
        b   0   0   1   2   2   2   5
        a   0   0   0   0   2   4   4
        b   0   0   0   0   0   0  [4]              
        
        if char is a match:
            sum up its upper left diognal and left column (which denotes the total possible permutations)
        else:
            copy its left column value           
*/
